#include <iostream>

const int BOARD_SIZE = 9;
const int EMPTY_CELL = 0;

bool findEmptyCell(int board[BOARD_SIZE][BOARD_SIZE], int& row, int& col);
bool spaceAvailable(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num);
bool solveSudoku(int board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    return 0;
}

bool findEmptyCell(int board[BOARD_SIZE][BOARD_SIZE], int& row, int& col)
{
    for (row = 0; row < BOARD_SIZE; ++row)
    {
        for (col = 0; col < BOARD_SIZE; ++col)
        {
            if (board[row][col] == EMPTY_CELL)
            {
                return true;  // Found an empty cell.
            }
        }
    }
    return false;  // No empty cell found.
}

bool spaceAvailable(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num)
{
    // Check if num is already present in the same row or column
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }

    // Check if num is already present in the same 3X3 board.
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }
    return true;  // If num doesn't conflict with any other number, space is available. 
}

bool solveSudoku(int board[BOARD_SIZE][BOARD_SIZE])
{
    int row = 0, col = 0;

    if (!findEmptyCell(board, row, col)) { return true; }  // If no empty cell is found, the puzzle is solved.

    for (int num = 1; num <= BOARD_SIZE; ++num)
    {
        if (spaceAvailable(board, row, col))
        {
            board[row][col] = num;

            if (solveSudoku(board)) { return true; }  // Recursively solve the Sudoku.
            board[row][col] = EMPTY_CELL;  // Undo the choice and try another number.
        }
    }
    return false;  // If no number can be placed, backtrack.
}
