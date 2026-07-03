/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* stack[10000]; 
    int top = -1;
    
    struct TreeNode* curr = root;
    
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        k--;
        
        if (k == 0) {
            return curr->val;
        }
        curr = curr->right;
    }
    
    return -1;
}
