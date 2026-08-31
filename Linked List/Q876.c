/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp=head;
    int l=0;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    int i;
    if(l%2==0){
        i=l/2;
    }else{
        i=1 + l/2;
    }
    int p=0;
    temp=head;
    while(p<i){
        temp=temp->next;
        p++;
    }
    return temp;
}
