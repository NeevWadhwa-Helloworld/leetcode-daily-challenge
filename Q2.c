/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* a1=l1;
    struct ListNode* a2=l2;
    struct ListNode* a3=NULL;
    struct ListNode* head_a3=NULL;
    int carry=0;
    int e1,e2;
    while(a1!=NULL || a2!=NULL || carry!=0){
        if(a1==NULL){
            e1=0;
        }else{
            e1=a1->val;
            a1=a1->next;
        }

        if(a2==NULL){
            e2=0;
        }else{
            e2=a2->val;
            a2=a2->next;
        }
        struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=(e1+e2+carry)%10;
        carry=(e1+e2+carry)/10;
        temp->next=NULL;
        if(a3==NULL){
            a3=temp;
            head_a3=a3;
        }else{
            a3->next=temp;
            a3=a3->next;
            a3->next=NULL;
        }
    }
    
    return head_a3;
}
