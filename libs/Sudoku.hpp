/*
 * Created by: Milosz Barylowicz
 * Date:       17/11/2021
*/

#pragma once

#include <array>

namespace sudoku
{

using board = std::array<std::array<int, 9>, 9>;
using position = std::tuple<int, int>;

bool solve(board&);
void print_board(const board&);
position find_empty_spot(const board&);
bool validate(const board&, int, const position&);

bool check_row(const board&, int, const position&);
bool check_column(const board&, int, const position&);
bool check_grid(const board&, int, const position&);
position determin_square_position_in_grid(const position&);

}
