typedef struct {
    int r;
    int c;
} Point;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int maxQueueSize = rows * cols;
    Point* queue = (Point*)malloc(maxQueueSize * sizeof(Point));
    int head = 0;
    int tail = 0;
    
    int freshCount = 0;
    int minutes = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[tail++] = (Point){i, j};
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }
    if (freshCount == 0) {
        free(queue);
        return 0;
    }
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (head < tail && freshCount > 0) {
        int currentLayerSize = tail - head;
        minutes++;
        
        for (int k = 0; k < currentLayerSize; k++) {
            Point curr = queue[head++];
            
            for (int d = 0; d < 4; d++) {
                int nr = curr.r + dr[d];
                int nc = curr.c + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    queue[tail++] = (Point){nr, nc};
                }
            }
        }
    }
    
    free(queue);
    return (freshCount == 0) ? minutes : -1;
}
