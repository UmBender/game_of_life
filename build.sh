#!/bin/bash

touch *.c
gcc main.c -o main --Wall -lm -O3

./main
