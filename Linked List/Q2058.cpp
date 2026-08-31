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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return{-1,-1};
        }
        ListNode* temp=head->next;
        ListNode* prev=head;
        vector<int> index;
        int i=1;
        while(temp->next!=nullptr){
            if(((temp->val > prev->val) && (temp->val > temp->next->val)) || ((temp->val < prev->val) && (temp->val < temp->next->val))){
                index.push_back(i);
            }
            prev=temp;
            temp=temp->next;
            i++;
        }
        int n=index.size();
        if(n<2){
            return {-1,-1};
        }

        int min_d= INT_MAX;
        int max_d=index.back()-index.front();
        for(int j=1;j<n;j++){
            min_d = min(min_d, index[j] - index[j - 1]);
        }
        return {min_d,max_d};
    }
};
