#!/bin/bash

# Generate parser with yacc
yacc -d -y --debug --verbose 22101291.y
echo 'Generated the parser C file as well the header file'

# Compile parser
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'

# Generate scanner with flex
flex 22101291.l
echo 'Generated the scanner C file'

# Compile scanner
g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'

# Link all together
g++ y.o l.o -o parser
echo 'All ready, running'

# Run the parser
./parser input.txt
echo 'Output written to 22101291_log.txt'
