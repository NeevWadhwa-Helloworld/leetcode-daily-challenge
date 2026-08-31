/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        newNode->random = NULL;
        
        curr->next = newNode;
        curr = newNode->next;
    }
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    struct Node* copyTail = dummy;
    curr = head;
    
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        
        copyTail->next = copy;
        copyTail = copy;
        
        curr = curr->next;
    }
    
    struct Node* result = dummy->next;
    free(dummy);
    return result;
}
