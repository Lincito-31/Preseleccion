#!/bin/bash

g++ grader.cpp doll.cpp -o doll.exe
for x in {1..3};do
    echo "file"
    ./doll.exe < examples/$x.in
    echo "---------"
done
