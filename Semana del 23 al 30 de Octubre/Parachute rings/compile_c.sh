#!/bin/bash

NAME=rings

/usr/bin/gcc -DEVAL -Wall -static -O2 -o $NAME grader.c $NAME.c -lm
