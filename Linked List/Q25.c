/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prevGroupTail = &dummy;
    struct ListNode *curr = head;

    while (curr) {
        struct ListNode *kthNode = curr;
        for (int i = 1; i < k && kthNode; i++) {
            kthNode = kthNode->next;
        }
        if (!kthNode) break;

        struct ListNode *nextGroupHead = kthNode->next;
        struct ListNode *prev = nextGroupHead;
        struct ListNode *groupCurr = curr;
        for (int i = 0; i < k; i++) {
            struct ListNode *tmp = groupCurr->next;
            groupCurr->next = prev;
            prev = groupCurr;
            groupCurr = tmp;
        }
        struct ListNode *temp = prevGroupTail->next;
        prevGroupTail->next = kthNode;
        prevGroupTail = temp;
        curr = nextGroupHead;
    }

    return dummy.next;
}
