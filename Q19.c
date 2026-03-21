/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head->next==NULL && n==1){
        free(head);
        return NULL;
    }
    int l=1;
    struct ListNode* temp=head;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    int p=l-n+1;
    if(p==1){
        struct ListNode* newHead=head->next;
        free(head);
        return newHead;
    }
    int i=1;
    temp=head;
    struct ListNode* prev=NULL;
    while(i<p){
        i++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}
