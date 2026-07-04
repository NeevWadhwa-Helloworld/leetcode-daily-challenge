typedef struct {
    int* heap;
    int size;
    int capacity;
} KthLargest;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyDown(int* heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        minHeapifyDown(heap, size, smallest);
    }
}

void minHeapifyUp(int* heap, int idx) {
    while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        swap(&heap[(idx - 1) / 2], &heap[idx]);
        idx = (idx - 1) / 2;
    }
}

void heapPush(KthLargest* obj, int val) {
    obj->heap[obj->size] = val;
    minHeapifyUp(obj->heap, obj->size);
    obj->size++;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            heapPush(obj, nums[i]);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            minHeapifyDown(obj->heap, obj->size, 0);
        }
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        heapPush(obj, val);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        minHeapifyDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
