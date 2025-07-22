#!/bin/bash

g++ grader.cpp werewolf.cpp -o werewolf.exe
for x in {1..2};do
    echo "file $x"
    ./werewolf.exe < examples/$x.in
    echo "---------"
done
