bool canPartition(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    if (totalSum % 2 != 0) {
        return false;
    }
    
    int target = totalSum / 2;
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int j = target; j >= num; j--) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
        if (dp[target]) {
            free(dp);
            return true;
        }
    }
    
    bool result = dp[target];
    free(dp);
    return result;
}
