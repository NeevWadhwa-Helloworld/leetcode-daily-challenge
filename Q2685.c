void dfs(int u, int n, int matrix[50][50], bool visited[], int component[], int *comp_size) {
    visited[u] = true;
    component[(*comp_size)++] = u;
    
    for (int v = 0; v < n; v++) {
        if (matrix[u][v] && !visited[v]) {
            dfs(v, n, matrix, visited, component, comp_size);
        }
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int matrix[50][50];
    bool visited[50];
    for (int i = 0; i < 50; i++) {
        visited[i] = false;
        for (int j = 0; j < 50; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    int complete_components_count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int component[50];
            int comp_size = 0;
            dfs(i, n, matrix, visited, component, &comp_size);
            bool is_complete = true;
            for (int j = 0; j < comp_size; j++) {
                for (int k = j + 1; k < comp_size; k++) {
                    if (!matrix[component[j]][component[k]]) {
                        is_complete = false;
                        break;
                    }
                }
                if (!is_complete) break;
            }
            
            if (is_complete) {
                complete_components_count++;
            }
        }
    }

    return complete_components_count;
}
