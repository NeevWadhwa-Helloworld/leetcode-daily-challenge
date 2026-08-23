char* getPermutation(int n, int k) {
    int* nums = (int*)malloc(n * sizeof(int));
    int* fact = (int*)malloc(n * sizeof(int));
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int f = 1;
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
        f *= (i + 1);
        fact[i] = f;
    }
    k--;
    for (int i = 0; i < n; i++) {
        int divisor = (i < n - 1) ? fact[n - 2 - i] : 1;
        int index = k / divisor;
        
        result[i] = nums[index] + '0';
        for (int j = index; j < n - 1 - i; j++) {
            nums[j] = nums[j + 1];
        }
        
        k %= divisor;
    }
    
    result[n] = '\0';
    
    free(nums);
    free(fact);
    return result;
}
