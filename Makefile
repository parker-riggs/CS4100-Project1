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

.PHONY: all build run test clean

# Default target: build tools and run the full pipeline.
all: run

build: $(SCANNER) $(CMOS)

$(LEX_C): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(SCANNER): $(LEX_C)
	$(CC) $(CFLAGS) -o $(SCANNER) $(LEX_C) -lfl

$(CMOS): $(CPP_SRC)
	$(CXX) $(CXXFLAGS) -o $(CMOS) $(CPP_SRC)

# Run full detector pipeline against EXAMPLES_DIR (default: Examples).
run: build
	bash ./$(DETECTOR) $(EXAMPLES_DIR)

# Test target:
# 1) Ensure each file in EXAMPLES_DIR can be tokenized.
# 2) Ensure full detector run generates a non-empty plagiarism report.
test: build
	@set -e; \
	count=0; \
	for f in ./$(EXAMPLES_DIR)/*; do \
		if [ -f "$$f" ]; then \
			echo "[TEST] Tokenizing $${f#./$(EXAMPLES_DIR)/}"; \
			./$(SCANNER) < "$$f"; \
			if [ ! -s scanner_out.txt ]; then \
				echo "[FAIL] scanner_out.txt is empty after tokenizing $$f"; \
				exit 1; \
			fi; \
			count=$$((count + 1)); \
		fi; \
	done; \
	echo "[TEST] Tokenized $$count files successfully."; \
	echo "[TEST] Running full detector..."; \
	bash ./$(DETECTOR) $(EXAMPLES_DIR); \
	if [ ! -s PlagarismReport.txt ]; then \
		echo "[FAIL] PlagarismReport.txt was not created or is empty."; \
		exit 1; \
	fi; \
	echo "[PASS] make test completed successfully."

clean:
	rm -f $(LEX_C) $(SCANNER) $(CMOS) scanner_out.txt tokens.txt PlagarismReport.txt