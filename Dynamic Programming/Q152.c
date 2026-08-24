#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int current = nums[i];
        if (current < 0) {
            int temp = max_so_far;
            max_so_far = min_so_far;
            min_so_far = temp;
        }
        max_so_far = MAX(current, max_so_far * current);
        min_so_far = MIN(current, min_so_far * current);
        result = MAX(result, max_so_far);
    }

    return result;
}
