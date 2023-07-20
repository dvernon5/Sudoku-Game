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

void generateRandomPuzzle(int board[BOARD_SIZE][BOARD_SIZE])
{
    // Start with a solved board.
    int solveBoard[BOARD_SIZE][BOARD_SIZE] = {
        { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
        { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 1, 7, 9 }
    };

    // Randomly remove cells to create the puzzle.
    int numCellsToRemove = 40;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j] = solveBoard[i][j];
        }
    }
    removeCells(board, numCellsToRemove);
}

void removeCells(int board[BOARD_SIZE][BOARD_SIZE], int numCellsToRemove)
{
    std::srand(std::time(0));  // Send the random number generator. 

    while (numCellsToRemove > 0)
    {
        int row = std::rand() % BOARD_SIZE;
        int col = std::rand() % BOARD_SIZE;

        if (board[row][col] != EMPTY_CELL)
        {
            int temp = board[row][col];
            board[row][col] = EMPTY_CELL;

            // Check if the puzzle still has a unique solution after removing the cell.
            int tempBoard[BOARD_SIZE][BOARD_SIZE];
            for (int i = 0; i < BOARD_SIZE; ++i)
            {
                for (int j = 0; j < BOARD_SIZE; ++j)
                {
                    tempBoard[i][j] = board[i][j];
                }
            }

            if (!solveSudoku(tempBoard))
            {
                // If the puzzle is no longer solvable or has multiple solutions, undo the removal
                board[row][col] = temp;
            }

            --numCellsToRemove;
        }
    }
}
