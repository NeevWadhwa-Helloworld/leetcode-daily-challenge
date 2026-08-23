char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* zero = (char*)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int totalLen = len1 + len2;
    
    int* result = (int*)calloc(totalLen, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    char* ans = (char*)malloc((totalLen + 1) * sizeof(char));
    int idx = 0;
    int i = 0;
    
    while (i < totalLen && result[i] == 0) {
        i++;
    }

    while (i < totalLen) {
        ans[idx++] = result[i++] + '0';
    }
    ans[idx] = '\0';

    free(result);
    return ans;
}
