/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int totalDigits = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = nums[i];
        if (temp == 0) totalDigits++;
        while (temp > 0) {
            temp /= 10;
            totalDigits++;
        }
    }

    int* result = (int*)malloc(sizeof(int) * totalDigits);
    *returnSize = totalDigits;
    int index = totalDigits - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        int n = nums[i];
        if (n == 0) {
            result[index--] = 0;
        } else {
            while (n > 0) {
                result[index--] = n % 10;
                n /= 10;
            }
        }
    }

    return result;
}
