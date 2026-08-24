/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void freeResult(char*** result, int* resultSizes, int resultSize) {
    for (int i = 0; i < resultSize; i++) {
        for (int j = 0; j < resultSizes[i]; j++) {
            free(result[i][j]);
        }
        free(result[i]);
    }
    free(result);
    free(resultSizes);
}

void backtrack(char* s, int start, int len, bool** isPalindrome, 
               char** currentPath, int pathSize, 
               char**** result, int* resultSize, int** resultSizes, int* capacity) {
    if (start == len) {
        if (*resultSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *resultSizes = realloc(*resultSizes, (*capacity) * sizeof(int));
        }
        (*result)[*resultSize] = malloc(pathSize * sizeof(char*));
        for (int i = 0; i < pathSize; i++) {
            (*result)[*resultSize][i] = strdup(currentPath[i]);
        }
        (*resultSizes)[*resultSize] = pathSize;
        (*resultSize)++;
        return;
    }
    for (int end = start; end < len; end++) {
        if (isPalindrome[start][end]) {
            int subLen = end - start + 1;
            char* subStr = malloc((subLen + 1) * sizeof(char));
            strncpy(subStr, s + start, subLen);
            subStr[subLen] = '\0';
            currentPath[pathSize] = subStr;
            backtrack(s, end + 1, len, isPalindrome, currentPath, pathSize + 1, result, resultSize, resultSizes, capacity);
            free(subStr);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    *returnSize = 0;
    
    if (len == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    bool** isPalindrome = malloc(len * sizeof(bool*));
    for (int i = 0; i < len; i++) {
        isPalindrome[i] = calloc(len, sizeof(bool));
    }
    for (int right = 0; right < len; right++) {
        for (int left = 0; left <= right; left++) {
            if (s[left] == s[right] && (right - left <= 2 || isPalindrome[left + 1][right - 1])) {
                isPalindrome[left][right] = true;
            }
        }
    }
    int capacity = 10;
    char*** result = malloc(capacity * sizeof(char**));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    
    char** currentPath = malloc(len * sizeof(char*));
    backtrack(s, 0, len, isPalindrome, currentPath, 0, &result, returnSize, returnColumnSizes, &capacity);
    for (int i = 0; i < len; i++) {
        free(isPalindrome[i]);
    }
    free(isPalindrome);
    free(currentPath);
    
    return result;
}
