int expandAroundCenter(char *s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) == 0) {
        char *empty = (char *)malloc(sizeof(char));
        *empty = '\0';
        return empty;
    }

    int len = strlen(s);
    int start = 0;
    int maxLen = 0;

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i, len);
        int len2 = expandAroundCenter(s, i, i + 1, len);
        int currentLen = (len1 > len2) ? len1 : len2;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            start = i - (currentLen - 1) / 2;
        }
    }
    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
