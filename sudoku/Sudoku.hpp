#pragma once

#include <array>
#include <tuple>

namespace sudoku
{

using sudoku_board = std::array<std::array<int, 9>, 9>;
using position = std::tuple<int, int>;

bool solve(sudoku_board&);
void print_board(const sudoku_board&);
position find_empty_spot(const sudoku_board&);
bool validate(const sudoku_board&, int, position);

bool check_row(const sudoku_board&, int, position);
bool check_column(const sudoku_board&, int, position);
bool check_grid(const sudoku_board&, int, position);
position determin_square_position_in_grid(const position);

}