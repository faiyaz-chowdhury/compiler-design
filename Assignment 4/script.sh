#!/bin/bash

# Two-pass compiler build and execution script
yacc -d -y --debug --verbose 22101848_22101069.y
echo 'Parser C file and header file generated'
g++ -w -c -o y.o y.tab.c
echo 'Parser object file created'
flex 22101848_22101069.l
echo 'Scanner C file generated'
g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Scanner object file created'
g++ y.o l.o -o two_pass_compiler
echo 'Compilation complete, executing two-pass compiler...'

# Execute the compiler on the input file
./two_pass_compiler input.c
echo 'Compilation process finished.'

# Display output files
echo '------------ Log File Output ------------'
cat log.txt
echo '------------ Error File Output ------------'
cat error.txt
echo '------------ Three Address Code Output ------------'
cat code.txt
