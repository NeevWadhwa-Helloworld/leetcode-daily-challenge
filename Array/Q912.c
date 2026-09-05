/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Merge function: Combines two sorted sub-arrays into one sorted section.
 */
void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;      // Pointer for left half
    int j = mid + 1;   // Pointer for right half
    int k = left;      // Pointer for temp array

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // Copy remaining elements of left half
    while (i <= mid) temp[k++] = nums[i++];
    
    // Copy remaining elements of right half
    while (j <= right) temp[k++] = nums[j++];

    // Copy the sorted temp array back into the original array
    for (int p = left; p <= right; p++) {
        nums[p] = temp[p];
    }
}

/**
 * Recursive function to divide the array.
 */
void mergeSort(int* nums, int left, int right, int* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        
        merge(nums, left, mid, right, temp);
    }
}

/**
 * Main function requested by LeetCode.
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    // Allocate a temporary auxiliary array once to save time/memory
    int* temp = (int*)malloc(numsSize * sizeof(int));
    
    mergeSort(nums, 0, numsSize - 1, temp);
    
    free(temp);
    return nums;
}
