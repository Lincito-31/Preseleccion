#!/bin/bash

NAME=rings

g++ -DEVAL -Wall -static -O2 -o $NAME grader.cpp $NAME.cpp
