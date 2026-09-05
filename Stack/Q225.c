typedef struct QueueNode {
    int val;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int val) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->val = val;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    QueueNode* temp = q->front;
    int val = temp->val;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

int queueFront(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->front->val;
}

void freeQueue(Queue* q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    int size = 0;
    QueueNode* curr = obj->q->front;
    while (curr) {
        size++;
        curr = curr->next;
    }
    enqueue(obj->q, x);
    for (int i = 0; i < size; i++) {
        enqueue(obj->q, dequeue(obj->q));
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(obj->q);
}

int myStackTop(MyStack* obj) {
    return queueFront(obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q);
    free(obj);
}
