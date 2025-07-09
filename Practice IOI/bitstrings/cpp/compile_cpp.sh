#!/bin/bash

problem="bitstrings"
grader_name="grader"

g++ -std=gnu++20 -Wall -O2 -pipe -static -g -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
