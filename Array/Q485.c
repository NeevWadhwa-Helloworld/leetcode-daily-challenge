#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_count = 0;
    int current_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            current_count++;
            max_count = MAX(max_count, current_count);
        } else {
            current_count = 0;
        }
    }

    return max_count;
}
