#include <iostream>
#include "Sudoku.hpp"

namespace sudoku
{

namespace
{
	enum {
		X = 0,
		Y = 1
	};
}

// function to solve sudoku board using backtrack algorithm
bool solve(sudoku_board& board)
{
	auto [x, y] = find_empty_spot(board);
	if (x == -1 and y == -1)
	{
		return true;
	}
	else
	{
		for (int num = 1; num < 10; ++num)
		{
			if (validate(board, num, std::make_tuple(x, y)))
			{
				board[x][y] = num;

				if (solve(board))
				{
					return true;
				}

				board[x][y] = 0;
			}
		}
	}

	return false;
}

// function to print sudoku board to console
void print_board(const sudoku_board& board)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		if (i % 3 == 0 and i != 0)
		{
			std::cout << "- - - - - - - - - - - -\n";
		}

		for (size_t k = 0; k < board[i].size(); ++k)
		{
			if (k % 3 == 0 and k != 0)
			{
				std::cout << " | ";
			}
			std::cout << board[i][k] << " ";
		}
		std::cout << std::endl;
	}
}

// find positon of empty element in sudoku board
position find_empty_spot(const sudoku_board& board)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t k = 0; k < board[i].size(); ++k)
		{
			if (board[i][k] == 0)
			{
				return { i, k };
			}
		}
	}
	return { -1, -1 };
}

// validate if inserted number fits (check row, column and squere that number is in)
bool validate(const sudoku_board& board, int num, position position)
{
	return check_row(board, num, position) and check_column(board, num, position) and check_grid(board, num, position);
}

bool check_row(const sudoku_board& board, int num, position position)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		if (board[std::get<X>(position)][i] == num and i != std::get<X>(position))
		{
			return false;
		}
	}
	return true;
}

bool check_column(const sudoku_board& board, int num, position position)
{
	for (size_t i = 0; i < board.size(); ++i)
	{
		if (board[i][std::get<Y>(position)] == num and i != std::get<X>(position))
		{
			return false;
		}
	}
	return true;
}

bool check_grid(const sudoku_board& board, int num, position position)
{
	const auto [x, y] = determin_square_position_in_grid(position);

	for (int k = x * 3; k < x * 3 + 2; ++k)
	{
		for (int i = y * 3; i < y * 3 + 2; ++i)
		{
			if (board[k][i] == num and position != std::make_tuple(i, k))
			{
				return false;
			}

		}
	}
	return true;
}

position determin_square_position_in_grid(const position position)
{
	auto y = std::get<Y>(position) / 3;
	auto x = std::get<X>(position) / 3;

	return {x, y};
}

}