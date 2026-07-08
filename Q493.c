int mergeAndCount(int* nums, int left, int mid, int right, int* temp) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int mergeSort(int* nums, int left, int right, int* temp) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    int count = 0;
    count += mergeSort(nums, left, mid, temp);
    count += mergeSort(nums, mid + 1, right, temp);
    count += mergeAndCount(nums, left, mid, right, temp);

    return count;
}

int reversePairs(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int result = mergeSort(nums, 0, numsSize - 1, temp);
    
    free(temp);
    return result;
}
