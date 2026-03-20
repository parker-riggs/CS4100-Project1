#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace {

// These constants control how much token data is grouped together for each
// comparison step. Tokens are stored as 3-digit strings, so a k-mer length of
// 12 means each hashed chunk covers 4 tokens at a time.
constexpr std::size_t KMER_LENGTH = 12;
constexpr std::size_t WINDOW_SIZE = 5;

// One entry from tokens.txt. Each submission keeps the original file name, the
// full token stream with spaces removed, and the final fingerprint set used for
// pairwise similarity comparisons.
struct Submission {
	std::string file_name;
	std::string token_stream;
	std::unordered_set<std::uint64_t> fingerprints;
};

// Stores the computed similarity information for a single pair of submissions.
// The report is built from a list of these objects and then sorted from most
// similar to least similar.
struct MatchResult {
	std::string left_file;
	std::string right_file;
	std::size_t shared_fingerprints;
	std::size_t total_fingerprints;
	double similarity;
};

// Hashes a string of token digits into a 64-bit value. This uses the FNV-1a
// pattern because it is simple and gives a stable integer for each k-mer substring.
std::uint64_t hash_text(const std::string& text) {
	std::uint64_t hash_value = 1469598103934665603ULL;

	// Mix each character into the running hash so similar k-mers can still map
	// to different values when even one token changes.
	for (unsigned char character : text) {
		hash_value ^= static_cast<std::uint64_t>(character);
		hash_value *= 1099511628211ULL;
	}

	return hash_value;
}

// Breaks the full token stream into overlapping substrings of length
// KMER_LENGTH and hashes each one. This is the first step of the winnowing
// process described in the project prompt.
std::vector<std::uint64_t> build_kmer_hashes(const std::string& token_stream) {
	std::vector<std::uint64_t> hashes;

	// An empty token stream has no k-mers and therefore no fingerprints.
	if (token_stream.empty()) {
		return hashes;
	}

	// If the submission is shorter than one normal k-mer, hash the entire string
	// once so the file can still participate in comparisons.
	if (token_stream.size() <= KMER_LENGTH) {
		hashes.push_back(hash_text(token_stream));
		return hashes;
	}

	// There are (n - k + 1) overlapping substrings of length k.
	hashes.reserve(token_stream.size() - KMER_LENGTH + 1);

	// Slide one character at a time across the digit string so every overlapping
	// k-mer is included.
	for (std::size_t index = 0; index + KMER_LENGTH <= token_stream.size(); ++index) {
		hashes.push_back(hash_text(token_stream.substr(index, KMER_LENGTH)));
	}

	return hashes;
}

// Applies the winnowing step: move a window over the k-mer hashes and keep the
// minimum hash from each window as that window's fingerprint. Using a set here
// removes duplicates so repeated minima are only counted once per submission.
std::unordered_set<std::uint64_t> build_fingerprints(const std::string& token_stream) {
	const std::vector<std::uint64_t> hashes = build_kmer_hashes(token_stream);
	std::unordered_set<std::uint64_t> fingerprints;

	// No hashes = no fingerprints.
	if (hashes.empty()) {
		return fingerprints;
	}

	// If there are fewer hashes than one full window, choose the smallest hash in
	// the entire list so the submission still gets one representative fingerprint.
	if (hashes.size() <= WINDOW_SIZE) {
		auto minimum_iterator = std::min_element(hashes.begin(), hashes.end());
		fingerprints.insert(*minimum_iterator);
		return fingerprints;
	}

	// Tracks the previous minimum position so the same minimum is not re-added on
	// consecutive overlapping windows unless the minimum position actually moves.
	std::size_t previous_minimum_index = hashes.size();

	// Each pass examines one contiguous window of hash values.
	for (std::size_t start = 0; start + WINDOW_SIZE <= hashes.size(); ++start) {
		std::size_t minimum_index = start;

		// Find the minimum hash in the current window. Ties go to the rightmost
		// minimum because of the <= comparison, which is a common winnowing choice.
		for (std::size_t offset = 1; offset < WINDOW_SIZE; ++offset) {
			const std::size_t current_index = start + offset;
			if (hashes[current_index] <= hashes[minimum_index]) {
				minimum_index = current_index;
			}
		}

		// Only record a new fingerprint when the chosen minimum position changes.
		// This prevents a long run of overlapping windows from repeatedly adding the
		// exact same selected minimum.
		if (minimum_index != previous_minimum_index) {
			fingerprints.insert(hashes[minimum_index]);
			previous_minimum_index = minimum_index;
		}
	}

	return fingerprints;
}

// Reads tokens.txt, where each line starts with a file name followed by a list
// of 3-digit tokens. The spaces between tokens are removed so the program can
// treat the entire submission as one continuous digit string.
std::vector<Submission> load_submissions(const std::string& file_path) {
	std::ifstream input_stream(file_path);
	std::vector<Submission> submissions;

	// If tokens.txt cannot be opened, return an empty list and let main print an
	// empty report instead of crashing.
	if (!input_stream) {
		std::cerr << "Unable to open " << file_path << '\n';
		return submissions;
	}

	std::string line;
	while (std::getline(input_stream, line)) {
		// Skip blank lines so they do not create empty submissions.
		if (line.empty()) {
			continue;
		}

		std::istringstream line_stream(line);
		Submission submission;
		// The first entry on each line is the original source file name.
		line_stream >> submission.file_name;

		if (submission.file_name.empty()) {
			continue;
		}

		std::string token;
		// Concatenate every numeric token into a single string like
		// "001040070..." so k-mers can be generated over the exact token sequence.
		while (line_stream >> token) {
			submission.token_stream += token;
		}

		// Precompute fingerprints once during loading so later pairwise comparison
		// work only has to compare sets instead of rebuilding them every time.
		submission.fingerprints = build_fingerprints(submission.token_stream);
		submissions.push_back(std::move(submission));
	}

	return submissions;
}

// Compares two submissions by counting how many fingerprints they share. The
// similarity score is based on the Jaccard-style ratio shared / union.
MatchResult compare_submissions(const Submission& left, const Submission& right) {
	// Iterate over the smaller set for fewer hash lookups.
	const auto& smaller_set = left.fingerprints.size() <= right.fingerprints.size()
		? left.fingerprints
		: right.fingerprints;
	const auto& larger_set = left.fingerprints.size() <= right.fingerprints.size()
		? right.fingerprints
		: left.fingerprints;

	std::size_t shared_count = 0;
	// Count fingerprints that appear in both submissions.
	for (std::uint64_t fingerprint : smaller_set) {
		if (larger_set.find(fingerprint) != larger_set.end()) {
			++shared_count;
		}
	}

	// Set union size = |A| + |B| - |A ∩ B|.
	const std::size_t total_count = left.fingerprints.size() + right.fingerprints.size() - shared_count;
	// Guard against divide-by-zero if both submissions somehow have no
	// fingerprints after preprocessing.
	const double similarity = total_count == 0
		? 0.0
		: static_cast<double>(shared_count) / static_cast<double>(total_count);

	return MatchResult{left.file_name, right.file_name, shared_count, total_count, similarity};
}

// Generates every unique pair of submissions, computes their similarity, and
// sorts the final results so the most suspicious pairs appear first.
std::vector<MatchResult> rank_matches(const std::vector<Submission>& submissions) {
	std::vector<MatchResult> results;

	// Compare every file against every file that comes after it. This avoids
	// duplicate pairs like A vs B and B vs A, and also avoids A vs A.
	for (std::size_t left_index = 0; left_index < submissions.size(); ++left_index) {
		for (std::size_t right_index = left_index + 1; right_index < submissions.size(); ++right_index) {
			results.push_back(compare_submissions(submissions[left_index], submissions[right_index]));
		}
	}

	// Highest similarity should appear first. Additional tie-breakers make the
	// output deterministic so repeated runs print pairs in the same order.
	std::sort(results.begin(), results.end(), [](const MatchResult& left, const MatchResult& right) {
		if (left.similarity != right.similarity) {
			return left.similarity > right.similarity;
		}

		if (left.shared_fingerprints != right.shared_fingerprints) {
			return left.shared_fingerprints > right.shared_fingerprints;
		}

		if (left.left_file != right.left_file) {
			return left.left_file < right.left_file;
		}

		return left.right_file < right.right_file;
	});

	return results;
}

// Keep only comparisons that involve target_file. This supports one-vs-all
// mode when CMOS is called like: ./cmos bills_01.c
std::vector<MatchResult> rank_matches_for_target(const std::vector<Submission>& submissions,
		const std::string& target_file) {
	std::vector<MatchResult> results;

	for (std::size_t left_index = 0; left_index < submissions.size(); ++left_index) {
		for (std::size_t right_index = left_index + 1; right_index < submissions.size(); ++right_index) {
			const Submission& left = submissions[left_index];
			const Submission& right = submissions[right_index];
			if (left.file_name == target_file || right.file_name == target_file) {
				results.push_back(compare_submissions(left, right));
			}
		}
	}

	std::sort(results.begin(), results.end(), [](const MatchResult& left, const MatchResult& right) {
		if (left.similarity != right.similarity) {
			return left.similarity > right.similarity;
		}

		if (left.shared_fingerprints != right.shared_fingerprints) {
			return left.shared_fingerprints > right.shared_fingerprints;
		}

		if (left.left_file != right.left_file) {
			return left.left_file < right.left_file;
		}

		return left.right_file < right.right_file;
	});

	return results;
}

// Accept either bare file names (bills_01.c) or paths (Examples/bills_01.c).
std::string basename_only(const std::string& input_path) {
	const std::size_t separator = input_path.find_last_of("/\\");
	if (separator == std::string::npos) {
		return input_path;
	}
	return input_path.substr(separator + 1);
}

// Prints a plain-text report to standard output. The provided shell script
// redirects this output into PlagarismReport.txt.
void print_report(const std::vector<Submission>& submissions, const std::vector<MatchResult>& results) {
	std::cout << "CMOS Winnowing Report\n";
	std::cout << "Submissions analyzed: " << submissions.size() << '\n';
	std::cout << "k-mer length: " << KMER_LENGTH << " digits\n";
	std::cout << "window size: " << WINDOW_SIZE << " hashes\n\n";

	// If there are fewer than two valid submissions, there are no pairs to rank.
	if (results.empty()) {
		std::cout << "No comparable submission pairs found.\n";
		return;
	}

	// Print similarity values with a fixed number of decimal places so the report
	// is easy to scan and compare.
	std::cout << std::fixed << std::setprecision(4);

	for (std::size_t index = 0; index < results.size(); ++index) {
		const MatchResult& result = results[index];
		// Each line contains the pair, the similarity score, and the counts used to
		// compute that score.
		std::cout << std::setw(2) << index + 1 << ". "
				  << result.left_file << " vs " << result.right_file
				  << " | similarity=" << result.similarity
				  << " | shared=" << result.shared_fingerprints
				  << " | total=" << result.total_fingerprints << '\n';
	}
}

}  // namespace

int main(int argc, char* argv[]) {
	// Load every tokenized submission from tokens.txt, compare all pairs, and
	// write the ranked report to stdout.
	if (argc > 2) {
		std::cerr << "Usage: ./cmos [target_file]" << '\n';
		return 1;
	}

	const std::vector<Submission> submissions = load_submissions("tokens.txt");

	std::vector<MatchResult> results;
	if (argc == 2) {
		const std::string target_file = basename_only(argv[1]);
		const bool target_exists = std::any_of(submissions.begin(), submissions.end(),
				[&target_file](const Submission& submission) {
					return submission.file_name == target_file;
				});

		if (!target_exists) {
			std::cerr << "Target file not found in tokens.txt: " << target_file << '\n';
			return 1;
		}

		results = rank_matches_for_target(submissions, target_file);
	} else {
		results = rank_matches(submissions);
	}

	print_report(submissions, results);
	return 0;
}