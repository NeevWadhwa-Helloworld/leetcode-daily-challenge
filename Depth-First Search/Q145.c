/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void fillPostorder(struct TreeNode* root, int* res, int* index) {
    if (!root) return;
    
    fillPostorder(root->left, res, index);
    fillPostorder(root->right, res, index);
    res[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* res = (int*)malloc((*returnSize) * sizeof(int));
    int index = 0;
    
    fillPostorder(root, res, &index);
    return res;
}
