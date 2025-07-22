#!/bin/bash
g++ grader.cpp paint.cpp -o paint.exe
for x in {1..5};do
    echo "file $x"
    ./paint.exe < examples/0$x
    echo "----"
done