#include <iostream>
#include <vector>
using namespace std;

void printSudoku(vector<vector<int>> &board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+-------\n";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            if (board[i][j] == 0)
                cout << "  ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool isValid(vector<vector<int>> &board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        // Row and column check
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }


    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve(board))
                            return true;
                        board[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}


int main() {
    string input;
    input="530070000600195000098000060800060003400803001700020006060000280000419005000080079";

    if (input.size() != 81) {
        cout << "Invalid input length.\n";
        return 1;
    }

    vector<vector<int>> board(9, vector<int>(9));

    for (int i = 0; i < 81; i++) {
        board[i / 9][i % 9] = input[i] - '0';
    }

    cout << "\nOriginal Puzzle:\n";
    printSudoku(board);

    if (solve(board)) {
        cout << "\nSolved Puzzle:\n";
        printSudoku(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
