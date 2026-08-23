long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int compare(const void *a, const void *b) {
    long long valA = *(const long long *)a;
    long long valB = *(const long long *)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

long long gcdSum(int* nums, int numsSize) {
    long long* prefixGcd = (long long*)malloc(numsSize * sizeof(long long));
    
    long long currentMax = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > currentMax) {
            currentMax = nums[i];
        }
        prefixGcd[i] = gcd(nums[i], currentMax);
    }
    
    qsort(prefixGcd, numsSize, sizeof(long long), compare);
    
    long long totalSum = 0;
    int l = 0;
    int r = numsSize - 1;
    
    while (l < r) {
        totalSum += gcd(prefixGcd[l], prefixGcd[r]);
        l++;
        r--;
    }
    
    free(prefixGcd);
    
    return totalSum;
}
