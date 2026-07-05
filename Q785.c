bool dfs(int node, int color, int* colors, int** graph, int* graphColSize) {
    colors[node] = color;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == 0) {
            if (!dfs(neighbor, -color, colors, graph, graphColSize)) {
                return false;
            }
        }
        else if (colors[neighbor] == colors[node]) {
            return false;
        }
    }
    
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* colors = (int*)calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == 0) {
            if (!dfs(i, 1, colors, graph, graphColSize)) {
                free(colors);
                return false;
            }
        }
    }
    
    free(colors);
    return true;
}
