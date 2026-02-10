#!/bin/bash

yacc -d -y --debug --verbose 22101848_22101069.y
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex 22101848_22101069.l
echo 'Generated the scanner C file'
g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
g++ y.o l.o -o a.out
echo 'All ready, running'
./a.out input.c
echo 'Compilation complete'
echo ''
echo '===== Log File ====='
cat 22101848_22101069_log.txt
echo ''
echo '===== Error File ====='
cat 22101848_22101069_error.txt
