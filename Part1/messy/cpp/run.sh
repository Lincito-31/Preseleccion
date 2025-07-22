#!/bin/bash
g++ grader.cpp messy.cpp -o messy.exe
for x in {1..1};do
    echo "file $x"
    ./messy.exe < examples/0$x
    echo "----"
done