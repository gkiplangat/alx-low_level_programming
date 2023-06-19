#!/bin/bash
gcc -c -Wall -Werror -Wextra -pedantic -std=gnu89 -fpic *.c
gcc -shared -o liball.so *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
