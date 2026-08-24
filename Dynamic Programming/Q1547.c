int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minCost(int n, int* cuts, int cutsSize) {
    int m = cutsSize + 2;
    int* arr = (int*)malloc(sizeof(int) * m);
    arr[0] = 0;
    for (int i = 0; i < cutsSize; i++) arr[i + 1] = cuts[i];
    arr[m - 1] = n;
    
    qsort(arr, m, sizeof(int), compare);
    int dp[m][m];
    memset(dp, 0, sizeof(dp));
    for (int len = 2; len < m; len++) {
        for (int i = 0; i < m - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int current_cost = dp[i][k] + dp[k][j] + (arr[j] - arr[i]);
                if (current_cost < dp[i][j]) {
                    dp[i][j] = current_cost;
                }
            }
        }
    }
    
    int result = dp[0][m - 1];
    free(arr);
    return result;
}
