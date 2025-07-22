#!/bin/bash
g++ gen.cpp -o gen.exe
for x in {8..20};do
    ./gen.exe > examples/0$x
done