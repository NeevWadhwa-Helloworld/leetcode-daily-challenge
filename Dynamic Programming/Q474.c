#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int k = 0; k < strsSize; k++) {
        int zeros = 0;
        int ones = 0;
        char* str = strs[k];
        for (int l = 0; str[l] != '\0'; l++) {
            if (str[l] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                dp[i][j] = MAX(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}
