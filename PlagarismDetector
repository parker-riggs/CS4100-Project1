#!/bin/bash
FILES=./"$1"/*
dirEntered="$1"
len=${#dirEntered}
len=$(($len+3))
rm tokens.txt
for f in $FILES
do
  echo "Tokenizing ${f:len} file..."
  # take action on each file. $f store current file name
	./scanner < $f
	echo -ne "${f:len}">>tokens.txt
	echo -ne " ">>tokens.txt
	cat scanner_out.txt >> tokens.txt
	echo "">>tokens.txt
done
echo "Detecting Plagarism, this may take a few minutes."
./cmos > PlagarismReport.txt
echo "Done. Results stored in PlagarismReport.txt"
