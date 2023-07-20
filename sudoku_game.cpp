#include <iostream>


const int BOARD_SIZE = 9;
const int EMPTY_CELL = 0;

bool findEmptyCell(int board[BOARD_SIZE][BOARD_SIZE], int& row, int& col)
{
    for (row = 0; row < BOARD_SIZE; ++row)
    {
        for (col = 0; col < BOARD_SIZE; ++col)
        {
            if (board[row][col] == EMPTY_CELL)
            {
                return true;
            }
        }
    }
    return false;
}
