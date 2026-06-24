/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd,int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];
    root->left = NULL;
    root->right = NULL;
    int inRootIdx = inStart;
    while (inRootIdx <= inEnd && inorder[inRootIdx] != root->val) {
        inRootIdx++;
    }
    int leftTreeSize = inRootIdx - inStart;
    root->left = buildTreeHelper(inorder, inStart, inRootIdx - 1,
                                 postorder, postStart, postStart + leftTreeSize - 1);
    root->right = buildTreeHelper(inorder, inRootIdx + 1, inEnd,
                                  postorder, postStart + leftTreeSize, postEnd - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0) return NULL;
    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
