int repeatedStringMatch(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int count = (lenB + lenA - 1) / lenA;
    int maxLen = lenA * (count + 2) + 1;
    char* repeatedA = (char*)malloc(maxLen * sizeof(char));
    repeatedA[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(repeatedA, a);
    }
    if (strstr(repeatedA, b) != NULL) {
        free(repeatedA);
        return count;
    }
    strcat(repeatedA, a);
    if (strstr(repeatedA, b) != NULL) {
        free(repeatedA);
        return count + 1;
    }
    strcat(repeatedA, a);
    if (strstr(repeatedA, b) != NULL) {
        free(repeatedA);
        return count + 2;
    }
    free(repeatedA);
    return -1;
}
