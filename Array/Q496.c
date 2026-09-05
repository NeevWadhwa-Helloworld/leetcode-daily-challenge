/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map[10001];
    memset(map, -1, sizeof(map));
    int* stack = (int*)malloc(sizeof(int) * nums2Size);
    int top = -1;
    for (int i = 0; i < nums2Size; i++) {
        int current = nums2[i];
        while (top >= 0 && current > stack[top]) {
            int popped_element = stack[top--];
            map[popped_element] = current;
        }
        stack[++top] = current;
    }
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }
    free(stack);
    *returnSize = nums1Size;
    return result;
}
