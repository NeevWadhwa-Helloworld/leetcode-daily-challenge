/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int start, int* path, int pathSize, int*** res, int* resSize, int** colSizes) {
    if (target == 0) {
        (*res) = (int**)realloc(*res, (*resSize + 1) * sizeof(int*));
        (*colSizes) = (int*)realloc(*colSizes, (*resSize + 1) * sizeof(int));
        (*res)[*resSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++) (*res)[*resSize][i] = path[i];
        (*colSizes)[*resSize] = pathSize;
        (*resSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;

        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, 
                  path, pathSize + 1, res, resSize, colSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, 
                      int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int** res = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    int* path = (int*)malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, path, 0, &res, returnSize, returnColumnSizes);
    
    free(path);
    return res;
}
