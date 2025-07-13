#!/bin/bash

g++ B.cpp -o B.exe
echo "compiled"

for x in {1..1}; do
    echo "Running test $x output i get:"
    ./B.exe < inputs/in$x
    echo ""
    echo "---------------------"
done