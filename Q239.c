/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int resultIdx = 0;
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int head = 0;
    int tail = 0;

    for (int i = 0; i < numsSize; i++) {
        if (head < tail && deque[head] < i - k + 1) {
            head++;
        }
        while (head < tail && nums[deque[tail - 1]] <= nums[i]) {
            tail--;
        }
        deque[tail++] = i;
        if (i >= k - 1) {
            result[resultIdx++] = nums[deque[head]];
        }
    }

    free(deque);
    *returnSize = resultIdx;
    return result;
}
