int maxSubArray(int* nums, int numsSize) {
    int max_so_far = nums[0];
    int current_sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
        } else {
            current_sum = current_sum + nums[i];
        }
        if (current_sum > max_so_far) {
            max_so_far = current_sum;
        }
    }
    return max_so_far;
}
