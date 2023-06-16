#!/bin/bash

touch *.c
touch ./cgl/*.*
gcc main.c ./cgl/cgl.c  -o main -Wall  -lm -O3


./main
