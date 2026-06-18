char* countAndSay(int n) {
    if (n == 1) return strdup("1");

    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* curr = (char*)malloc(sizeof(char) * (2 * len + 1));
    int currIdx = 0;

    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i + 1 < len && prev[i] == prev[i + 1]) {
            count++;
            i++;
        }
        currIdx += sprintf(curr + currIdx, "%d%c", count, prev[i]);
    }
    
    curr[currIdx] = '\0';
    free(prev);
    return curr;
}
