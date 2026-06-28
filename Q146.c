typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int key;
    Node *node;
} HashEntry;

typedef struct {
    int capacity;
    int size;
    int hashSize;
    HashEntry *hashTable;
    Node *head;
    Node *tail;
} LRUCache;

int hash(int key, int hashSize) {
    return abs(key) % hashSize;
}

Node* createNode(int key, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void insertFront(LRUCache *obj, Node *node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

Node* findNode(LRUCache *obj, int key) {
    int idx = hash(key, obj->hashSize);

    while (obj->hashTable[idx].node != NULL) {
        if (obj->hashTable[idx].key == key)
            return obj->hashTable[idx].node;

        idx = (idx + 1) % obj->hashSize;
    }
    return NULL;
}

void insertHash(LRUCache *obj, int key, Node *node) {
    int idx = hash(key, obj->hashSize);

    while (obj->hashTable[idx].node != NULL)
        idx = (idx + 1) % obj->hashSize;

    obj->hashTable[idx].key = key;
    obj->hashTable[idx].node = node;
}

void deleteHash(LRUCache *obj, int key) {
    int idx = hash(key, obj->hashSize);

    while (obj->hashTable[idx].node != NULL) {
        if (obj->hashTable[idx].key == key) {
            obj->hashTable[idx].node = NULL;
            return;
        }
        idx = (idx + 1) % obj->hashSize;
    }
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache*)malloc(sizeof(LRUCache));

    obj->capacity = capacity;
    obj->size = 0;
    obj->hashSize = 10007;

    obj->hashTable = (HashEntry*)calloc(obj->hashSize, sizeof(HashEntry));

    obj->head = createNode(0, 0);
    obj->tail = createNode(0, 0);

    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node *node = findNode(obj, key);

    if (node == NULL)
        return -1;

    removeNode(node);
    insertFront(obj, node);

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node *node = findNode(obj, key);

    if (node != NULL) {
        node->value = value;
        removeNode(node);
        insertFront(obj, node);
        return;
    }

    if (obj->size == obj->capacity) {
        Node *lru = obj->tail->prev;
        removeNode(lru);
        deleteHash(obj, lru->key);
        free(lru);
        obj->size--;
    }

    Node *newNode = createNode(key, value);
    insertFront(obj, newNode);
    insertHash(obj, key, newNode);
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node *curr = obj->head;
    while (curr) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(obj->hashTable);
    free(obj);
}
