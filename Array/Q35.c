int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        // Find the middle index
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid; // Target found!
        } else if (nums[mid] < target) {
            low = mid + 1; // Target is in the right half
        } else {
            high = mid - 1; // Target is in the left half
        }
    }

    // If not found, 'low' is the index where it should be inserted
    return low;
}
