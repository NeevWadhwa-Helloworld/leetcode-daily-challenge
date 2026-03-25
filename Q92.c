/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left==right){
        return head;
    }
    struct ListNode* temp=head;
    int i=1;
    struct ListNode* A=NULL;
    struct ListNode* B=NULL;
    struct ListNode* prev_A=NULL;
    struct ListNode* next_B=NULL;
    while(temp!=NULL){
        if(i==left-1){
            prev_A=temp;
        }
        if(i==right+1){
            next_B=temp;
        }
        if(i==left){
            A=temp;
        }
        if(i==right){
            B=temp;
        }
        temp=temp->next;
        i++;
    }
    i=0;
    temp=head;
    struct ListNode* prev=next_B;
    struct ListNode* curr=A;
    struct ListNode* nextNode=NULL;
    while(prev!=B){
        nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    if (prev_A == NULL) {
        return B;
    } else {
        prev_A->next = B;
        return head;
    }
}
