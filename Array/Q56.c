/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    return rowA[0] - rowB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;
    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= currentEnd) {
            if (intervals[i][1] > currentEnd) {
                currentEnd = intervals[i][1];
            }
        } else {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = currentStart;
            result[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;
            currentStart = intervals[i][0];
            currentEnd = intervals[i][1];
        }
    }
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = currentStart;
    result[count][1] = currentEnd;
    (*returnColumnSizes)[count] = 2;
    count++;

    *returnSize = count;
    return result;
}
