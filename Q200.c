void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    if (r < 0 || r >= gridSize || c < 0 || c >= gridColSize[r] || grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0';
    dfs(grid, gridSize, gridColSize, r - 1, c);
    dfs(grid, gridSize, gridColSize, r + 1, c);
    dfs(grid, gridSize, gridColSize, r, c - 1);
    dfs(grid, gridSize, gridColSize, r, c + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0 || gridColSize == NULL) {
        return 0;
    }

    int islandCount = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                islandCount++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }

    return islandCount;
}
