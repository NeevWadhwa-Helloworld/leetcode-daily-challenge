bool isNonDecreasing(int* nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int operations = 0;
    while (!isNonDecreasing(nums, numsSize)) {
        int minSum = INT_MAX;
        int targetIdx = -1;
        for (int i = 0; i < numsSize - 1; i++) {
            int currentSum = nums[i] + nums[i + 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                targetIdx = i;
            }
        }
        nums[targetIdx] = minSum;
        for (int i = targetIdx + 1; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }

        numsSize--;
        operations++;
    }

    return operations;
}
