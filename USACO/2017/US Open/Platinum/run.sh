#!/bin/bash
g++ A.cpp -o A.exe
for x in {1..3};do
    echo "file$x"
    ./A.exe < input$x
    echo ""
    echo "------"
done