/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);
    int leftmost[26];
    int rightmost[26];
    for (int i = 0; i < 26; i++) {
        leftmost[i] = n;
        rightmost[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        leftmost[idx] = MIN(leftmost[idx], i);
        rightmost[idx] = i;
    }
    int* res_left = (int*)malloc(sizeof(int) * 26);
    int* res_right = (int*)malloc(sizeof(int) * 26);
    int count = 0;
    
    int last_right = -1;
    
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (i != leftmost[idx]) continue;
        
        int new_right = rightmost[idx];
        int valid = 1;
        for (int j = i + 1; j <= new_right; j++) {
            int inner_idx = s[j] - 'a';
            if (leftmost[inner_idx] < i) {
                valid = 0;
                break;
            }
            new_right = MAX(new_right, rightmost[inner_idx]);
        }
        
        if (valid) {
            if (new_right < last_right && count > 0) {
                res_left[count - 1] = i;
                res_right[count - 1] = new_right;
            }
            else if (i > last_right) {
                res_left[count] = i;
                res_right[count] = new_right;
                count++;
            }
            last_right = new_right;
        }
    }
    char** result = (char**)malloc(sizeof(char*) * count);
    for (int i = 0; i < count; i++) {
        int len = res_right[i] - res_left[i] + 1;
        result[i] = (char*)malloc(sizeof(char) * (len + 1));
        strncpy(result[i], s + res_left[i], len);
        result[i][len] = '\0';
    }
    
    free(res_left);
    free(res_right);
    
    *returnSize = count;
    return result;
}
