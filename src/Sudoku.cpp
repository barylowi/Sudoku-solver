/*
 * Created by: Milosz Barylowicz
 * Date:       17/11/2021
 */

#include "../libs/Sudoku.hpp"
#include <tuple>
#include <iostream>

namespace sudoku
{
namespace
{
    enum
    {
        X = 0,
        Y = 1
    };
}

bool solve(board& board)
{
    auto [x, y] = find_empty_spot(board);
    if (x == -1 and y == -1)
    {
        return true;
    }
    else
    {
        for (size_t num = 1; num < 10; ++num)
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

void print_board(const board& board)
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

position find_empty_spot(const board& board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t k = 0; k < board[i].size(); ++k)
        {
            if (board[i][k] == 0)
            {
                return std::make_tuple(i, k);
            }
        }
    }
    return std::make_tuple(-1, -1);
}

bool validate(const board& board, int num, const position& position)
{
    return check_row(board, num, position) and check_column(board, num, position) and check_grid(board, num, position);
}

bool check_row(const board& board, int num, const position& position)
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

bool check_column(const board& board, int num, const position& position)
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

bool check_grid(const board& board, int num, const position& position)
{
    const auto [x, y] = determin_square_position_in_grid(position);
    for (size_t k = x * 3; k < x * 3 + 2; ++k)
    {
        for (size_t i = y * 3; i < y * 3 + 2; ++i)
        {
            if (board[k][i] == num and position != std::make_tuple(i, k))
            {
                return false;
            }
        }
    }
    return true;
}

position determin_square_position_in_grid(const position& position)
{
    auto y = std::get<Y>(position) / 3;
    auto x = std::get<X>(position) / 3;

    return std::make_tuple(x, y);
}

}
