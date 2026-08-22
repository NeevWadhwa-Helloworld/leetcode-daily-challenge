/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int val;
    int freq;
} Element;

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void minHeapify(Element* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        Element temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    if (numsSize == 0) return result;
    qsort(nums, numsSize, sizeof(int), compareInts);
    Element* uniqueElements = (Element*)malloc(numsSize * sizeof(Element));
    int uniqueSize = 0;

    uniqueElements[0].val = nums[0];
    uniqueElements[0].freq = 1;
    uniqueSize = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            uniqueElements[uniqueSize - 1].freq++;
        } else {
            uniqueElements[uniqueSize].val = nums[i];
            uniqueElements[uniqueSize].freq = 1;
            uniqueSize++;
        }
    }
    Element* heap = (Element*)malloc(k * sizeof(Element));
    int heapSize = 0;

    for (int i = 0; i < uniqueSize; i++) {
        if (heapSize < k) {
            heap[heapSize] = uniqueElements[i];
            int curr = heapSize;
            heapSize++;
            while (curr > 0 && heap[(curr - 1) / 2].freq > heap[curr].freq) {
                Element temp = heap[(curr - 1) / 2];
                heap[(curr - 1) / 2] = heap[curr];
                heap[curr] = temp;
                curr = (curr - 1) / 2;
            }
        } else if (uniqueElements[i].freq > heap[0].freq) {
            heap[0] = uniqueElements[i];
            minHeapify(heap, k, 0);
        }
    }
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }
    free(uniqueElements);
    free(heap);

    return result;
}
