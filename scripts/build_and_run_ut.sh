#!/bin/bash

# clear current directory
rm -r *

# take building and running steps
bash ../scripts/build_ut.sh
./sudoku_solver_tests