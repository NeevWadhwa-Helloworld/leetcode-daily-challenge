typedef struct {
    int price;
    int span;
} StackElement;

typedef struct {
    StackElement* elements;
    int top;
    int capacity;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* spanner = (StockSpanner*)malloc(sizeof(StockSpanner));
    spanner->capacity = 10005; 
    spanner->elements = (StackElement*)malloc(spanner->capacity * sizeof(StackElement));
    spanner->top = -1;
    return spanner;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int currentSpan = 1;
    while (obj->top >= 0 && obj->elements[obj->top].price <= price) {
        currentSpan += obj->elements[obj->top].span;
        obj->top--;
    }
    obj->top++;
    obj->elements[obj->top].price = price;
    obj->elements[obj->top].span = currentSpan;
    
    return currentSpan;
}

void stockSpannerFree(StockSpanner* obj) {
    if (obj) {
        free(obj->elements);
        free(obj);
    }
}
