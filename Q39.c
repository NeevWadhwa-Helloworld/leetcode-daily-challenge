/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void findCombinations(int* candidates, int candidatesSize, int target, int start, int* path, int pathSize, int*** res, int* resSize, int** colSizes) {
    if (target == 0) {
        (*res) = (int**)realloc(*res, sizeof(int*) * (*resSize + 1));
        (*colSizes) = (int*)realloc(*colSizes, sizeof(int) * (*resSize + 1));
        (*res)[*resSize] = (int*)malloc(sizeof(int) * pathSize);
        for (int i = 0; i < pathSize; i++) (*res)[*resSize][i] = path[i];
        (*colSizes)[*resSize] = pathSize;
        (*resSize)++;
        return;
    }
    
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            path[pathSize] = candidates[i];
            findCombinations(candidates, candidatesSize, target - candidates[i], i, 
                             path, pathSize + 1, res, resSize, colSizes);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int* path = (int*)malloc(sizeof(int) * 1000);
    
    findCombinations(candidates, candidatesSize, target, 0, path, 0, &res, returnSize, returnColumnSizes);
    
    free(path);
    return res;
}
