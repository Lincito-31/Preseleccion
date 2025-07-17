#!/bin/bash

g++ elephants.cpp grader.cpp -o X.exe

for x in {1..2};do
    echo "file $x"
    ./X.exe < grader.in.$x
    echo ""
    echo "----"
done