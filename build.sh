#!/bin/bash

touch *.c
touch ./cgl/*.*
gcc main.c ./cgl/cgl.c  -o main  -lm -O3


./main
