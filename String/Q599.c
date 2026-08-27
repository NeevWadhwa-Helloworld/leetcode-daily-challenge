/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize) {
    int min_sum = INT_MAX;
    char **result = (char **)malloc(sizeof(char *) * (list1Size > list2Size ? list2Size : list1Size));
    *returnSize = 0;

    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                int current_sum = i + j;

                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    *returnSize = 0;
                    result[(*returnSize)++] = list1[i];
                } 
                else if (current_sum == min_sum) {
                    result[(*returnSize)++] = list1[i];
                }
            }
        }
    }
    return result;
}
