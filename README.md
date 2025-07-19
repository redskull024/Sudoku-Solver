-----

# Sudoku Solver

This project provides a C++ implementation of a Sudoku solver that uses a backtracking algorithm to find solutions for standard 9x9 Sudoku puzzles.

-----

## How it Works

The solver takes a Sudoku puzzle as a string input, converts it into a 2D array, and then applies a **backtracking algorithm**.

1.  **`solve(board)` Function**: This is the core recursive function. It iterates through each cell of the Sudoku board.

      * If a cell is empty (represented by `0`), it tries to place numbers from 1 to 9.
      * For each number, it checks if the placement is valid using the `isValid` function.
      * If valid, it places the number and recursively calls `solve` for the next empty cell.
      * If the recursive call returns `true` (meaning a solution was found), it propagates `true` back up.
      * If the recursive call returns `false` (meaning the current path didn't lead to a solution), it **backtracks** by resetting the cell to `0` and tries the next number.
      * If all numbers from 1 to 9 have been tried for a cell and none lead to a solution, it returns `false`.
      * If all cells are filled, it returns `true`, indicating a solution has been found.

2.  **`isValid(board, row, col, num)` Function**: This helper function checks if placing a `num` at a given `row` and `col` is valid according to Sudoku rules:

      * It verifies if `num` is already present in the current `row`.
      * It verifies if `num` is already present in the current `col`.
      * It verifies if `num` is already present in the 3x3 subgrid (box) to which the `row` and `col` belong.

3.  **`printSudoku(board)` Function**: This function displays the Sudoku board in a user-friendly format, including separators for rows and columns to visually distinguish the 3x3 subgrids.

-----

## Getting Started

### Prerequisites

You need a C++ compiler (like g++) to compile and run this code.

### How to Compile and Run

1.  **Save the code**: Save the provided C++ code as `sudoku_solver.cpp`.

2.  **Compile**: Open your terminal or command prompt, navigate to the directory where you saved the file, and compile using:

    ```bash
    g++ sudoku_solver.cpp -o sudoku_solver
    ```

3.  **Run**: Execute the compiled program:

    ```bash
    ./sudoku_solver
    ```

-----

## Input Format

The Sudoku puzzle is provided as a **string of 81 characters** within the `main` function. Each character represents a cell in the 9x9 grid, read row by row.

  * **Digits '1' through '9'** represent pre-filled cells.
  * **'0'** represents an empty cell.

**Example Input:**
The current `main` function uses the following input:

```cpp
string input = "530070000600195000098000060800060003400803001700020006060000280000419005000080079";
```

This represents the following puzzle:

```
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
------+-------+------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6
------+-------+------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
```

(where `.` denotes an empty cell / `0`)

-----

## Output

The program will print:

1.  The **Original Puzzle** in a formatted grid.
2.  The **Solved Puzzle** in a formatted grid if a solution is found.
3.  A message "No solution exists." if the given puzzle is unsolvable.

-----

## Limitations

  * This solver is designed for **standard 9x9 Sudoku puzzles**.
  * It assumes valid Sudoku rules (each number 1-9 appears only once per row, column, and 3x3 subgrid).
  * For puzzles with multiple solutions, it will return only one of them.

-----

## Contributing

Feel free to fork the repository and contribute to improve the solver.

-----
