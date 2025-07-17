#!/bin/bash

g++ stub.cpp insects.cpp -o X.exe

for x in {1..2};do
    echo "file $x"
    ./X.exe < input$x
    echo ""
    echo "-------"
done