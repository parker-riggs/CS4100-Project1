# CS4100 Project 1

CMOS is a simplified plagiarism detector for C programs. It follows the same high-level process used by MOSS-style systems:

1. Tokenize each C source file with Lex/Flex.
2. Remove unimportant surface differences such as whitespace, comments, literal values, and identifier names.
3. Convert the token stream into overlapping k-mers.
4. Hash those k-mers and apply winnowing to select fingerprints.
5. Compare fingerprint sets across submissions and rank the most similar pairs.

This repository contains the tokenizer, the comparison engine, a driver script, and a sample corpus used for testing.

## Project Structure

- `cmos.l`: Lex/Flex scanner that tokenizes C source and writes tokens to `scanner_out.txt`
- `cmos.cpp`: C++ comparison program that reads `tokens.txt`, builds fingerprints, and prints a ranked report
- `PlagarismDetector`: Bash script that runs the full pipeline over a directory of example files
- `Examples/`: sample C submissions used to test the implementation
- `docs/Work.txt`: working notes for the project, mostly used in early stage.
- `Project1.pdf`: assignment specification

## How the Project Works

### 1. Tokenization

The scanner in `cmos.l` reads one C file at a time and emits a sequence of numeric tokens. The current lexer:

- ignores whitespace
- ignores line and block comments
- maps preprocessor include lines to a token
- maps control-flow keywords to tokens
- maps basic types to tokens
- maps string and character literals to generic literal tokens
- maps identifiers to one generic identifier token
- maps numbers to one generic numeric token
- maps operators and delimiters to numeric tokens

The scanner writes its output to `scanner_out.txt`, which is then appended into `tokens.txt` by the driver script.

### 2. Fingerprinting

The comparison logic in `cmos.cpp` reads `tokens.txt`. Each line contains:

- the original filename
- the token sequence for that submission

The program then:

1. removes spaces between tokens to form one continuous digit string
2. builds overlapping k-mers from that digit string
3. hashes each k-mer into a 64-bit value
4. slides a window across those hashes
5. selects the minimum hash in each window as a fingerprint

These fingerprints are used as the basis for similarity comparison.

### 3. Pairwise Comparison

For every unique pair of submissions, `cmos.cpp`:

1. counts the number of shared fingerprints
2. computes the union size of both fingerprint sets
3. calculates similarity as `shared / total`
4. sorts all pairs from highest similarity to lowest similarity

The final report is written to `PlagarismReport.txt` by redirecting the program's standard output.

## Current Parameters

The current comparison settings in `cmos.cpp` are:

- `KMER_LENGTH = 12`
- `WINDOW_SIZE = 5`

Because tokens are stored as 3-digit values, a k-mer length of 12 corresponds to 4 tokens per hashed chunk.

## Requirements

To build and run the project, you need:

- `flex`
- `g++`
- a Bash-compatible shell

## Build

Use the Makefile as the primary way to build, run, and test the project.

### Make Targets

1. `make`

- Default target (`all`)
- Builds both executables (`scanner` and `cmos`)
- Runs the full plagiarism pipeline on `Examples`

2. `make build`

- Builds only the binaries (`scanner`, `cmos`)
- Does not run tokenization or comparison

3. `make run`

- Builds if needed
- Runs `PlagarismDetector` on the configured examples directory
- Produces `tokens.txt` and `PlagarismReport.txt`

4. `make test bills_01.c`

- Builds if needed
- Requires one selected file name after `test` (for example `bills_01.c`)
- Tokenizes every file in the selected examples directory
- Runs `cmos` and filters the report to only `bills_01.c vs other_file.c` pairs
- Prints a final plagiarism decision for the selected file using a similarity threshold

5. `make clean`

- Removes generated artifacts (`lex.yy.c`, `scanner`, `cmos`, `scanner_out.txt`, `tokens.txt`, `PlagarismReport.txt`)

### Configure Input Directory and Threshold

The Makefile uses `EXAMPLES_DIR` (default: `Examples`) and `PLAGIARISM_THRESHOLD` (default: `0.80`).

Override them on any run/test command:

```bash
make run EXAMPLES_DIR=Examples
make test bills_01.c EXAMPLES_DIR=Examples
make test bills_01.c PLAGIARISM_THRESHOLD=0.70
```

## Run

Typical full-corpus run commands:

```bash
make
# or
make run
```

Both commands execute this flow:

1. Each .c file in the examples folder is tokenized into a normalized token stream.
2. Those token streams are then converted into fingerprint sets via k-mers and winnowing.
3. CMOS is then ran and compares every unique file pair in an all-vs-all manner instead of just one file.
4. For each pair, it computes similarities as shared fingerprints / total fingerprints.
5. All pairs are then sorted highest similarity first and written to PlagarismReport.txt

## Test One File Against All Others

Use this command style:

```bash
make test bills_01.c
```

This test flow does the following:

1. verifies that `Examples/bills_01.c` exists
2. tokenizes all files in `Examples/`
3. runs `cmos` once for all pairwise comparisons
4. keeps only report lines that include `bills_01.c`
5. prints one of these result messages:
	- `Potential plagiarism detected in bills_01.c ...`
	- `No plagiarism detected in bills_01.c ...`

Important: `[PASS]` means the pipeline ran successfully. The plagiarism verdict is the `[RESULT]` line.

## Output Files

- `scanner_out.txt`: token output for the most recently scanned file
- `tokens.txt`: one line per submission, combining the filename and its token stream
- `PlagarismReport.txt`: ranked similarity report for all file pairs

## Example Workflow

```bash
make clean
make build
make test bills_01.c
make run
```

Then inspect `PlagarismReport.txt` and manually review the highest-ranked pairs.

## Notes

- The script and report use the existing repository spelling `PlagarismDetector` and `PlagarismReport.txt`.
- The tokenizer is intentionally simplified for the assignment and does not aim to fully parse all of C.
- The example corpus in `Examples/` is the intended test set for this project.

## Future Improvements

- expand token coverage for more C constructs
- tune k-mer and window settings based on observed false positives and false negatives
- add sample report excerpts or evaluation notes to the documentation