#!/bin/bash

problem="quesitos"
memory=2097152  # 2GB
stack_size=2097152  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
python3 ./grader.py
