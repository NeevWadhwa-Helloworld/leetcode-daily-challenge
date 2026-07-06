typedef struct {
    int *data;
    int size;
    int capacity;
    int isMinHeap;
} Heap;

Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b, int isMinHeap) {
    if (isMinHeap) {
        return a < b; 
    }
    return a > b;  
}

void heapifyUp(Heap* h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (compare(h->data[index], h->data[parent], h->isMinHeap)) {
            swap(&h->data[index], &h->data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(Heap* h, int index) {
    int target = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && compare(h->data[left], h->data[target], h->isMinHeap)) {
        target = left;
    }
    if (right < h->size && compare(h->data[right], h->data[target], h->isMinHeap)) {
        target = right;
    }

    if (target != index) {
        swap(&h->data[index], &h->data[target]);
        heapifyDown(h, target);
    }
}

void push(Heap* h, int val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int*)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->size] = val;
    h->size++;
    heapifyUp(h, h->size - 1);
}

int pop(Heap* h) {
    if (h->size == 0) return 0;
    int topVal = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return topVal;
}

int peek(Heap* h) {
    return h->data[0];
}

typedef struct {
    Heap* maxHeap;
    Heap* minHeap;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createHeap(1000, 0);
    mf->minHeap = createHeap(1000, 1);
    return mf;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxHeap->size == 0 || num <= peek(obj->maxHeap)) {
        push(obj->maxHeap, num);
    } else {
        push(obj->minHeap, num);
    }
    if (obj->maxHeap->size > obj->minHeap->size + 1) {
        push(obj->minHeap, pop(obj->maxHeap));
    } else if (obj->minHeap->size > obj->maxHeap->size) {
        push(obj->maxHeap, pop(obj->minHeap));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxHeap->size > obj->minHeap->size) {
        return (double)peek(obj->maxHeap);
    } else {
        return (peek(obj->maxHeap) + peek(obj->minHeap)) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap->data);
    free(obj->maxHeap);
    free(obj->minHeap->data);
    free(obj->minHeap);
    free(obj);
}
