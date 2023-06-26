#!/bin/bash

touch *.c
touch ./cgl/*.*
gcc main.c ./cgl/cgl.c ./cgl/parser.c  -o main -Wall  -lm -O3


./main -L !@#%
