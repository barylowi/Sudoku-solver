#!/bin/bash

# clear build directory
rm -r *

# build project
bash ../scripts/build.sh

# run
./sudoku_solver