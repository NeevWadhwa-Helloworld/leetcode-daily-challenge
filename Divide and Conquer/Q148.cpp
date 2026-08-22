/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid=Solution::get_middle(head);
        ListNode* right_head=mid->next;
        mid->next=NULL;

        ListNode* left=Solution::sortList(head);
        ListNode* right=Solution::sortList(right_head);

        return Solution::merge(left,right);
    }

    ListNode* get_middle(ListNode* head){
        ListNode* slow;
        ListNode* fast;
        slow=head;
        fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while (l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next=(l1!=NULL)?l1:l2;
        return dummy.next;
    }
};
