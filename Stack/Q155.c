typedef struct {
    int val;
    int min;
} StackElement;

typedef struct {
    StackElement* data;
    int top_idx;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1000;
    obj->data = (StackElement*)malloc(obj->capacity * sizeof(StackElement));
    obj->top_idx = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top_idx == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (StackElement*)realloc(obj->data, obj->capacity * sizeof(StackElement));
    }
    
    obj->top_idx++;
    obj->data[obj->top_idx].val = val;
    if (obj->top_idx == 0) {
        obj->data[obj->top_idx].min = val;
    } else {
        int prev_min = obj->data[obj->top_idx - 1].min;
        obj->data[obj->top_idx].min = (val < prev_min) ? val : prev_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top_idx >= 0) {
        obj->top_idx--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top_idx].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top_idx].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}
