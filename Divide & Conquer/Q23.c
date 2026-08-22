/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    
    return dummy.next;
}

struct ListNode* mergeKListsHelper(struct ListNode** lists, int start, int end) {
    if (start > end) {
        return NULL;
    }
    if (start == end) {
        return lists[start];
    }
    
    int mid = start + (end - start) / 2;
    
    struct ListNode* leftMerged = mergeKListsHelper(lists, start, mid);
    struct ListNode* rightMerged = mergeKListsHelper(lists, mid + 1, end);
    
    return mergeTwoLists(leftMerged, rightMerged);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return mergeKListsHelper(lists, 0, listsSize - 1);
}
