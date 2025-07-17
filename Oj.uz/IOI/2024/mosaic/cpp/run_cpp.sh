#!/bin/bash

g++ grader.cpp mosaic.cpp -o X.exe
for x in {1..1};do
    echo "file $x"
    ./X.exe < input$x
    echo "---"
done