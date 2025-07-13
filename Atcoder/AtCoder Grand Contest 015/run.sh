#!/bin/bash

g++ C.cpp -o C.exe
for x in {1..2};do
    echo "file$x"
    ./C.exe < input$x
    echo ""
    echo "----------"
done