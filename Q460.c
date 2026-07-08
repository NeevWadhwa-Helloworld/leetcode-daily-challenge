typedef struct Node {
    int key;
    int value;
    int freq;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DList {
    Node* head;
    Node* tail;
} DList;

typedef struct HashEntry {
    int key;
    Node* node;
    struct HashEntry* next;
} HashEntry;

typedef struct {
    int capacity;
    int size;
    int min_freq;
    HashEntry** hash_table;
    int hash_capacity;
    DList* freq_map; 
    int max_freq_capacity;
} LFUCache;

DList* create_list() {
    DList* list = (DList*)malloc(sizeof(DList));
    list->head = (Node*)malloc(sizeof(Node));
    list->tail = (Node*)malloc(sizeof(Node));
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->head->prev = NULL;
    list->tail->next = NULL;
    return list;
}

void remove_node(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void add_to_head(DList* list, Node* node) {
    node->next = list->head->next;
    node->prev = list->head;
    list->head->next->prev = node;
    list->head->next = node;
}

bool is_list_empty(DList* list) {
    return list->head->next == list->tail;
}

int hash_code(int key, int capacity) {
    int code = key % capacity;
    return code < 0 ? code + capacity : code;
}

void hash_put(LFUCache* cache, int key, Node* node) {
    int idx = hash_code(key, cache->hash_capacity);
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->node = node;
    entry->next = cache->hash_table[idx];
    cache->hash_table[idx] = entry;
}

Node* hash_get(LFUCache* cache, int key) {
    int idx = hash_code(key, cache->hash_capacity);
    HashEntry* curr = cache->hash_table[idx];
    while (curr) {
        if (curr->key == key) return curr->node;
        curr = curr->next;
    }
    return NULL;
}

void hash_remove(LFUCache* cache, int key) {
    int idx = hash_code(key, cache->hash_capacity);
    HashEntry* curr = cache->hash_table[idx];
    HashEntry* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else cache->hash_table[idx] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void update_frequency(LFUCache* cache, Node* node) {
    int old_freq = node->freq;
    int new_freq = old_freq + 1;
    node->freq = new_freq;
    remove_node(node);
    if (old_freq == cache->min_freq && is_list_empty(&cache->freq_map[old_freq])) {
        cache->min_freq++;
    }
    if (new_freq >= cache->max_freq_capacity) {
        int old_cap = cache->max_freq_capacity;
        cache->max_freq_capacity *= 2;
        cache->freq_map = (DList*)realloc(cache->freq_map, sizeof(DList) * cache->max_freq_capacity);
        for (int i = old_cap; i < cache->max_freq_capacity; i++) {
            Node* h = (Node*)malloc(sizeof(Node));
            Node* t = (Node*)malloc(sizeof(Node));
            h->next = t; t->prev = h; h->prev = NULL; t->next = NULL;
            cache->freq_map[i].head = h;
            cache->freq_map[i].tail = t;
        }
    }
    add_to_head(&cache->freq_map[new_freq], node);
}

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->min_freq = 0;
    cache->hash_capacity = capacity > 0 ? capacity * 2 : 11;
    cache->hash_table = (HashEntry**)calloc(cache->hash_capacity, sizeof(HashEntry*));
    cache->max_freq_capacity = 2001;
    cache->freq_map = (DList*)malloc(sizeof(DList) * cache->max_freq_capacity);
    for (int i = 0; i < cache->max_freq_capacity; i++) {
        Node* h = (Node*)malloc(sizeof(Node));
        Node* t = (Node*)malloc(sizeof(Node));
        h->next = t; t->prev = h; h->prev = NULL; t->next = NULL;
        cache->freq_map[i].head = h;
        cache->freq_map[i].tail = t;
    }
    
    return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if (obj->capacity == 0) return -1;
    
    Node* node = hash_get(obj, key);
    if (!node) return -1;
    
    update_frequency(obj, node);
    return node->value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj->capacity == 0) return;
    
    Node* node = hash_get(obj, key);
    if (node) {
        node->value = value;
        update_frequency(obj, node);
    } else {
        if (obj->size == obj->capacity) {
            DList* min_list = &obj->freq_map[obj->min_freq];
            Node* to_evict = min_list->tail->prev;
            
            hash_remove(obj, to_evict->key);
            remove_node(to_evict);
            free(to_evict);
            obj->size--;
        }
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->key = key;
        new_node->value = value;
        new_node->freq = 1;
        
        hash_put(obj, key, new_node);
        add_to_head(&obj->freq_map[1], new_node);
        
        obj->min_freq = 1;
        obj->size++;
    }
}

void lFUCacheFree(LFUCache* obj) {
    for (int i = 0; i < obj->hash_capacity; i++) {
        HashEntry* curr = obj->hash_table[i];
        while (curr) {
            HashEntry* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(obj->hash_table);
    for (int i = 0; i < obj->max_freq_capacity; i++) {
        Node* curr = obj->freq_map[i].head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(obj->freq_map);
    free(obj);
}
