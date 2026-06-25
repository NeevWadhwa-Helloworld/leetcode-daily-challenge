int compare(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;
    
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare);

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        }
        if (nums[i] == nums[i - 1] + 1) {
            currentStreak++;
        } else {
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
            currentStreak = 1;
        }
    }
    if (currentStreak > longestStreak) {
        longestStreak = currentStreak;
    }

    return longestStreak;
}
