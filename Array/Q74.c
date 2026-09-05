bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int i = 0;
    int j = 0;
    while (i < m && matrix[i][0] <= target) {
        if (matrix[i][0] == target) return true;
        if (matrix[i][n - 1] >= target) {
            while (j < n) {
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] > target) return false;
                j++;
            }
        }
        i++;
    }
    return false;
}
