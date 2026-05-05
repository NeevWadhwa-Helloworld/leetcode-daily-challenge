/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool validate(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {
        return true;
    }
    if (node->val <= min || node->val >= max) {
        return false;
    }
    return validate(node->left, min, node->val) && 
           validate(node->right, node->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}
