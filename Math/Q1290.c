/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int res = 0;
    struct ListNode* temp = head;
    
    while (temp != NULL) {
        res = (res << 1) | temp->val;
        temp = temp->next;
    }
    
    return res;
}
