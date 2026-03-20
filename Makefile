LEX := flex
CC := gcc
CXX := g++

CFLAGS ?= -O2 -Wall -Wextra
CXXFLAGS ?= -O2 -Wall -Wextra -std=c++17

LEX_SRC := cmos.l
LEX_C := lex.yy.c
CPP_SRC := cmos.cpp

SCANNER := scanner
CMOS := cmos
DETECTOR := PlagarismDetector
EXAMPLES_DIR ?= Examples
PLAGIARISM_THRESHOLD ?= 0.80

ifeq ($(firstword $(MAKECMDGOALS)),test)
TEST_FILE := $(word 2,$(MAKECMDGOALS))
ifneq ($(TEST_FILE),)
.PHONY: $(TEST_FILE)
$(TEST_FILE):
	@:
endif
endif

.PHONY: all build tokens run test clean

# Default target: build tools and generate tokens.txt from EXAMPLES_DIR.
all: tokens

build: $(SCANNER) $(CMOS)

$(LEX_C): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(SCANNER): $(LEX_C)
	$(CC) $(CFLAGS) -o $(SCANNER) $(LEX_C)

$(CMOS): $(CPP_SRC)
	$(CXX) $(CXXFLAGS) -o $(CMOS) $(CPP_SRC)

# Generate tokens.txt from every file in EXAMPLES_DIR.
tokens: build
	@set -e; \
	count=0; \
	rm -f tokens.txt; \
	for f in ./$(EXAMPLES_DIR)/*; do \
		if [ -f "$$f" ]; then \
			echo "[TOKENS] Tokenizing $${f#./$(EXAMPLES_DIR)/}"; \
			./$(SCANNER) < "$$f"; \
			if [ ! -s scanner_out.txt ]; then \
				echo "[FAIL] scanner_out.txt is empty after tokenizing $$f"; \
				exit 1; \
			fi; \
			printf "%s " "$${f#./$(EXAMPLES_DIR)/}" >> tokens.txt; \
			tr '\n' ' ' < scanner_out.txt >> tokens.txt; \
			printf "\n" >> tokens.txt; \
			count=$$((count + 1)); \
		fi; \
	done; \
	echo "[TOKENS] Tokenized $$count files into tokens.txt"

# Build tokens and generate the full all-vs-all report.
run: tokens
	./$(CMOS) > PlagarismReport.txt

# Test target:
# 1) Tokenize every file in EXAMPLES_DIR.
# 2) Run CMOS once and keep only pairs that include the selected file.
# 3) Print a plagiarism decision based on PLAGIARISM_THRESHOLD.
# Usage: make test bills_01.c
test: tokens
	@set -e; \
	target="$(TEST_FILE)"; \
	if [ -z "$$target" ]; then \
		echo "[FAIL] A test file is required."; \
		echo "Usage: make test bills_01.c"; \
		exit 1; \
	fi; \
	if [ ! -f "./$(EXAMPLES_DIR)/$$target" ]; then \
		echo "[FAIL] File not found: ./$(EXAMPLES_DIR)/$$target"; \
		exit 1; \
	fi; \
	echo "[TEST] Running CMOS for $$target vs all others..."; \
	./$(CMOS) "$$target" > PlagarismReport.txt; \
	if [ ! -s PlagarismReport.txt ]; then \
		echo "[FAIL] PlagarismReport.txt was not created or is empty."; \
		exit 1; \
	fi; \
	if ! grep -q " vs " PlagarismReport.txt; then \
		echo "[FAIL] No comparison lines found for $$target."; \
		exit 1; \
	fi; \
	threshold="$(PLAGIARISM_THRESHOLD)"; \
	result=$$(awk -v target="$$target" ' \
		/ vs / { \
			line = $$0; \
			sub(/^[[:space:]]*[0-9]+\.[[:space:]]*/, "", line); \
			sub(/[[:space:]]*\|.*/, "", line); \
			split(line, names, " vs "); \
			if (names[1] == target) partner = names[2]; \
			else if (names[2] == target) partner = names[1]; \
			else next; \
			if (match($$0, /similarity=[0-9]*\.?[0-9]+/)) { \
				s = substr($$0, RSTART + 11, RLENGTH - 11) + 0; \
				if (!seen || s > max) { max = s; best = partner; seen = 1; } \
			} \
		} \
		END { if (seen) printf "%s|%.4f", best, max; } \
	' PlagarismReport.txt); \
	best_match=$${result%%|*}; \
	max_similarity=$${result##*|}; \
	if awk -v sim="$$max_similarity" -v th="$$threshold" 'BEGIN { exit !(sim >= th) }'; then \
		echo "[RESULT] Potential plagiarism detected in $$target (closest match: $$best_match, similarity=$$max_similarity, threshold=$$threshold)."; \
	else \
		echo "[RESULT] No plagiarism detected in $$target (max similarity=$$max_similarity, threshold=$$threshold)."; \
	fi; \
	echo "[PASS] make test completed successfully for $$target."

clean:
	rm -f $(LEX_C) $(SCANNER) $(CMOS) scanner_out.txt tokens.txt PlagarismReport.txt