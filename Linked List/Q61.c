/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k==0 || head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* temp=head;
    int l=1;
    while(temp->next!=NULL){
        temp=temp->next;
        l++;
    }
    
    
    
    k=k%l;
    if(k==0){
        return head;
    }
    struct ListNode* tail=head;
    while(tail->next->next!=NULL){
        tail=tail->next;
    }
    struct ListNode* newHead=tail->next;
    tail->next=NULL;
    newHead->next=head;
    head=newHead;
    return rotateRight(head,k-1);
}
