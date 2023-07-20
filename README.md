# Sudoku Game

This repository contains a C++ implementation of a Sudoku solver and a puzzle generator. The code allows you to generate random Sudoku puzzles with a specified difficulty level and solve any valid Sudoku puzzle.

## Sudoku Solver  

The Sudoku solver is implemented using a backtracking algorithm. It takes a 9X9 Sudoku grid as input and recursively tries to fill in the empty cells with numbers from 1 to 9, ensuring that no number is repeated in the same row, column, or 3X3 grid. If a valid solution exists, it returns true, and the solved Sudoku grid is updated in-place.

## How to use the Sudoku Solver
1. Make sure you have a valid Sudoku grid(9X9 array) with empty cells represented as 0.
2. Call the solveSudoku() function with your Sudoku grid as an argument.
3. If the function returns true, your Sudoku grid has been solved, and the updated grid contains the solution.

```shell
 // Example usage
int grid[GRID_SIZE][GRID_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
if (solveSudoku(grid)) {
    // Your Sudoku puzzle has been solved
    printGrid(grid);
} else {
    std::cout << "No solution exists." << std::endl;
}
```

## Sudoku Puzzle Generator
The Sudoku puzzle generator creates a random Sudoku puzzle with a specified difficulty level. It starts with a solved Sudoku grid and then randomly removes cells while ensuring that the puzzle remains solvable and has a unique solution.

### How to use the Sudoku Puzzle Generator
1. Call the generateRandomPuzzle() function with an empty 9X9 Sudoku grid as an argument. The function will update the grid with a randomly generated Sudoku puzzle.

```shell
// Example usage
int grid[GRID_SIZE][GRID_SIZE];

generateRandomPuzzle(grid);

std::cout << "Generated Sudoku Puzzle:" << std::endl;
printGrid(grid);
```

You can control the difficulty of the puzzle by adjusting the numCellsToRemove variable in the generateRandomPuzzle() function. A higher value of numCellsToRemove will result in a more challenging puzzle. 
