typedef struct {
    struct TreeNode** stack;
    int top;
    int capacity;
} BSTIterator;

void pushLeftNodes(BSTIterator* obj, struct TreeNode* root) {
    while (root != NULL) {
        if (obj->top + 1 >= obj->capacity) {
            obj->capacity *= 2;
            obj->stack = realloc(obj->stack, sizeof(struct TreeNode*) * obj->capacity);
        }
        obj->stack[++(obj->top)] = root;
        root = root->left;
    }
}
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->capacity = 1000;
    obj->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * obj->capacity);
    obj->top = -1;
    pushLeftNodes(obj, root);
    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* currNode = obj->stack[obj->top--];
    if (currNode->right != NULL) {
        pushLeftNodes(obj, currNode->right);
    }
    
    return currNode->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}
