/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = countNodes(root);
    *returnSize = size;
    
    int* result = (int*)malloc(sizeof(int) * size);
    int index = 0;
    
    inorder(root, result, &index);
    
    return result;
}
