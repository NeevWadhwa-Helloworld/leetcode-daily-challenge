/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = NULL;
    root->right = NULL;
    int inRootIdx = inStart;
    while (inRootIdx <= inEnd && inorder[inRootIdx] != root->val) {
        inRootIdx++;
    }
    int leftTreeSize = inRootIdx - inStart;
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, 
                                 inorder, inStart, inRootIdx - 1);
    root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, 
                                  inorder, inRootIdx + 1, inEnd);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) return NULL;
    return buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
