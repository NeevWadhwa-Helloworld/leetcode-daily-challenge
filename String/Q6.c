char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows <= 1 || numRows >= len) {
        return s;
    }
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int count = 0;
    int cycleLen = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            result[count++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[count++] = s[j + cycleLen - i];
            }
        }
    }
    
    result[count] = '\0';     
    return result;
}
