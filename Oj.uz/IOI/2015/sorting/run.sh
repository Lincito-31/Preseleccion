#!/bin/bash

g++ grader.cpp sorting.cpp -o X.exe

for x in {1..4};do
    echo "file $x"
    ./X.exe < sorting$x.in
    echo ""
    echo "-------"
done