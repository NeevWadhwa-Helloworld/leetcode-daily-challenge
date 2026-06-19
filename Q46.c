/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

void backtrack(int* nums, int numsSize, int start, int** res, int* resIndex) {
    if (start == numsSize) {
        res[*resIndex] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) res[*resIndex][i] = nums[i];
        (*resIndex)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, res, resIndex);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = factorial(numsSize);
    int** res = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    int resIndex = 0;
    backtrack(nums, numsSize, 0, res, &resIndex);
    return res;
}
