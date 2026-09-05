/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
int getDepth(struct TreeNode* node, int* diameter) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = getDepth(node->left, diameter);
    int rightDepth = getDepth(node->right, diameter);
    if (leftDepth + rightDepth > *diameter) {
        *diameter = leftDepth + rightDepth;
    }
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    getDepth(root, &diameter);
    return diameter;
}
