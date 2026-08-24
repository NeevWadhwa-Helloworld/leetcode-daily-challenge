int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int* tails = (int*)malloc(sizeof(int) * numsSize);
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int left = 0, right = size;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        tails[left] = x;
        if (left == size) {
            size++;
        }
    }

    free(tails);
    return size;
}
