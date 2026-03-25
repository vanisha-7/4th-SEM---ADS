#include <stdio.h>
#define N 4  // You can change N for different board sizes

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if placing queen is safe
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Solve N-Queens using backtracking
int solveNQueens(int board[N][N], int col) {
    if (col >= N)
        return 1; // All queens placed

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1))
                return 1;

            board[i][col] = 0; // Backtrack
        }
    }
    return 0; // No placement possible
}

// Main function
int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0))
        printBoard(board);
    else
        printf("No solution exists\n");

    return 0;
}