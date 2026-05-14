bool isGood(int* nums, int numsSize) {
    int n = numsSize - 1;
    if (numsSize < 2) return false;
    int* count = (int*)calloc(numsSize, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val < 1 || val > n) {
            free(count);
            return false;
        }
        count[val]++;
    }
    for (int i = 1; i < n; i++) {
        if (count[i] != 1) {
            free(count);
            return false;
        }
    }
    if (count[n] != 2) {
        free(count);
        return false;
    }

    free(count);
    return true;
}
