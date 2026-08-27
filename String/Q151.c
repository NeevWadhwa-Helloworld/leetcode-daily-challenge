void reverse(char* s, int begin, int end) {
    while (begin < end) {
        char temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int write_idx = 0;
    int read_idx = 0;
    
    while (read_idx < len) {
        while (read_idx < len && s[read_idx] == ' ') {
            read_idx++;
        }
        if (read_idx < len) {
            if (write_idx > 0) {
                s[write_idx++] = ' ';
            }
            while (read_idx < len && s[read_idx] != ' ') {
                s[write_idx++] = s[read_idx++];
            }
        }
    }
    s[write_idx] = '\0';
    int new_len = write_idx;
    reverse(s, 0, new_len - 1);
    int start = 0;
    for (int i = 0; i <= new_len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }

    return s;
}
