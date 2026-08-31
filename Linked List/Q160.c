/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;

    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;
    while (ptrA != ptrB) {
        if(ptrA==NULL){
            ptrA=headB;
        }else{
            ptrA=ptrA->next;
        }
        if(ptrB==NULL){
            ptrB=headA;
        }else{
            ptrB=ptrB->next;
        }
    }

    return ptrA; 
}
