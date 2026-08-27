#define ALPHABET_SIZE 26
typedef struct Trie {
    struct Trie* children[ALPHABET_SIZE];
    bool isEndOfWord;
} Trie;

Trie* trieCreate() {
    Trie* newNode = (Trie*)malloc(sizeof(Trie));
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void trieInsert(Trie* obj, char* word) {
    Trie* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; 
        if (curr->children[index] == NULL) {
            curr->children[index] = trieCreate();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie* curr = obj;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* curr = obj;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (obj->children[i] != NULL) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}
