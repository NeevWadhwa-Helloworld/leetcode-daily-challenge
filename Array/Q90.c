/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* current, int currentSize, 
               int*** result, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (*returnSize >= *capacity) {
        *capacity *= 2;
        *result = (int**)realloc(*result, sizeof(int*) * (*capacity));
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * (*capacity));
    }
    (*result)[*returnSize] = (int*)malloc(sizeof(int) * currentSize);
    for (int i = 0; i < currentSize; i++) {
        (*result)[*returnSize][i] = current[i];
    }
    (*returnColumnSizes)[*returnSize] = currentSize;
    (*returnSize)++;
    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, i + 1, current, currentSize + 1, 
                  result, returnSize, returnColumnSizes, capacity);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int capacity = 10;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    *returnSize = 0;
    
    int* current = (int*)malloc(sizeof(int) * numsSize);
    backtrack(nums, numsSize, 0, current, 0, &result, returnSize, returnColumnSizes, &capacity);
    
    free(current);
    return result;
}
