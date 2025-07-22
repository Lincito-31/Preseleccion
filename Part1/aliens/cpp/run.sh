#!/bin/bash
g++ grader.cpp aliens.cpp -o aliens.exe
for x in {1..20};do
    echo "file $x"
    ./aliens.exe < examples/0$x
    echo "--------"
done