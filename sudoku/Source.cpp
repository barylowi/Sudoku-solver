#include <iostream>
#include <array>
#include "Sudoku.hpp"

std::array<std::array<int, 9>, 9> board { 9, 4, 0,  0, 3, 1,  0, 0, 7,
										  6, 0, 0,  0, 0, 0,  0, 0, 0,
										  0, 0, 0,  0, 0, 2,  0, 0, 9,

										  0, 7, 0,  0, 6, 0,  2, 0, 0,
										  0, 9, 0,  0, 4, 0,  8, 0, 0,
										  0, 3, 0,  0, 0, 0,  5, 0, 0,

										  0, 0, 0,  0, 0, 0,  0, 0, 1,
										  0, 2, 0,  0, 8, 0,  0, 7, 0,
										  0, 0, 0,  0, 0, 0,  0, 4, 0 };

int main()
{
	sudoku::solve(board);
	sudoku::print_board(board);
}