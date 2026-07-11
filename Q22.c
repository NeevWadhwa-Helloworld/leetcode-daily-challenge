int getCatalanNumber(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * (n + i) / i;
    }
    return result / (n + 1);
}
void backtrack(int n, int open, int close, char* current, int index, char** result, int* returnSize) {
    if (index == 2 * n) {
        current[index] = '\0';
        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    if (open < n) {
        current[index] = '(';
        backtrack(n, open + 1, close, current, index + 1, result, returnSize);
    }
    if (close < open) {
        current[index] = ')';
        backtrack(n, open, close + 1, current, index + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if (n <= 0) return NULL;
    int totalCombinations = getCatalanNumber(n);
    char** result = malloc(totalCombinations * sizeof(char*));
    char* current = malloc((2 * n + 1) * sizeof(char));
    backtrack(n, 0, 0, current, 0, result, returnSize);
    free(current);

    return result;
}
