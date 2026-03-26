/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev=NULL;
    struct ListNode *curr=head;
    struct ListNode *nextNode=NULL;
    while(curr!=NULL){
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head) return true;

    struct ListNode *newHead = NULL;
    struct ListNode *tail = NULL;
    struct ListNode *temp = head;
    while(temp != NULL){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = temp->val;
        newNode->next = NULL;

        if(newHead == NULL){
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }
    struct ListNode* rev = reverseList(newHead);
    struct ListNode* p1 = head;
    struct ListNode* p2 = rev;
    while(p1 != NULL && p2 != NULL){
        if(p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
