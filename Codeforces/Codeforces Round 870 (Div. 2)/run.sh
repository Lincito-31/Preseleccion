#!/bin/bash

g++ D.cpp -o D.exe
for x in {1..1}; do
    echo "file$x"
    ./D.exe < input$x
    echo ""
    echo "-----"
done