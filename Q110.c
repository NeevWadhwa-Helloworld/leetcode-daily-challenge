/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int checkHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}
