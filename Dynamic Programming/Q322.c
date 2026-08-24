int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    int max_val = amount + 1;
    for (int i = 0; i <= amount; i++) {
        dp[i] = max_val;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    int result = dp[amount];
    free(dp);
    return (result > amount) ? -1 : result;
}
