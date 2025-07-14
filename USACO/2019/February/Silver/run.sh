#!/bin/bash

g++ B.cpp -o B.exe
for x in {1..2};do
    echo "file$x"
    ./B.exe < input$x.txt
    echo ""
    echo "--------"
done