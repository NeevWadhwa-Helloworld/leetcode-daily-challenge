/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void solve(int row, int n, int* queens, int* cols, int* diag1, int* diag2, char**** result, int* returnSize, int** columnSizes) {
    if (row == n) {
        (*result)[*returnSize] = (char**)malloc(n * sizeof(char*));
        (*columnSizes)[*returnSize] = n;
        for (int i = 0; i < n; i++) {
            (*result)[*returnSize][i] = (char*)malloc((n + 1) * sizeof(char));
            memset((*result)[*returnSize][i], '.', n);
            (*result)[*returnSize][i][n] = '\0';
            (*result)[*returnSize][i][queens[i]] = 'Q';
        }
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
            queens[row] = col;
            cols[col] = diag1[row - col + n] = diag2[row + col] = 1;
            
            solve(row + 1, n, queens, cols, diag1, diag2, result, returnSize, columnSizes);
            cols[col] = diag1[row - col + n] = diag2[row + col] = 0;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** columnSizes) {
    *returnSize = 0;
    char*** result = (char***)malloc(1000 * sizeof(char**));
    *columnSizes = (int*)malloc(1000 * sizeof(int));
    
    int* queens = (int*)malloc(n * sizeof(int));
    int* cols = (int*)calloc(n, sizeof(int));
    int* diag1 = (int*)calloc(2 * n, sizeof(int));
    int* diag2 = (int*)calloc(2 * n, sizeof(int));
    
    solve(0, n, queens, cols, diag1, diag2, &result, returnSize, columnSizes);
    
    return result;
}
