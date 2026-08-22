void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }
    for (int i = (k / 2) - 1; i >= 0; i--) {
        minHeapify(heap, k, i);
    }
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            minHeapify(heap, k, 0);
        }
    }
    int result = heap[0];
    free(heap);
    
    return result;
}
