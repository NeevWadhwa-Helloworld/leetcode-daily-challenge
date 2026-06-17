/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* build(int* preorder, int* index, int preorderSize, long long min, long long max) {
    if (*index >= preorderSize || preorder[*index] < min || preorder[*index] > max) {
        return NULL;
    }
    struct TreeNode* root = createNode(preorder[*index]);
    (*index)++;
    root->left = build(preorder, index, preorderSize, min, (long long)root->val);
    root->right = build(preorder, index, preorderSize, (long long)root->val, max);
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int index = 0;
    return build(preorder, &index, preorderSize, LONG_MIN, LONG_MAX);
}
