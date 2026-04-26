#define BUCKET_SIZE 10007
typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node** buckets;
} MyHashSet;


Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->buckets = (Node**)calloc(BUCKET_SIZE, sizeof(Node*));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int hash = key % BUCKET_SIZE;
    Node* curr = obj->buckets[hash];
    while (curr) {
        if (curr->key == key) return;
        curr = curr->next;
    }
    Node* newNode = createNode(key);
    newNode->next = obj->buckets[hash];
    obj->buckets[hash] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hash = key % BUCKET_SIZE;
    Node* curr = obj->buckets[hash];
    Node* prev = NULL;
    
    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                obj->buckets[hash] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int hash = key % BUCKET_SIZE;
    Node* curr = obj->buckets[hash];
    
    while (curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* curr = obj->buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj->buckets);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
