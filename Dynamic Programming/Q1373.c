/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    int isBST;
    int minVal;
    int maxVal;
    int sum;
} SubtreeInfo;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxBSTSum;

SubtreeInfo checkBST(struct TreeNode* root) {
    if (root == NULL) {
        return (SubtreeInfo){1, INT_MAX, INT_MIN, 0};
    }
    SubtreeInfo left = checkBST(root->left);
    SubtreeInfo right = checkBST(root->right);
    
    SubtreeInfo current;
    if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
        current.isBST = 1;
        current.minVal = (root->left != NULL) ? left.minVal : root->val;
        current.maxVal = (root->right != NULL) ? right.maxVal : root->val;
        current.sum = left.sum + right.sum + root->val;
        maxBSTSum = max(maxBSTSum, current.sum);
    } else {
        current.isBST = 0;
        current.minVal = 0;
        current.maxVal = 0;
        current.sum = 0;
    }
    
    return current;
}

int maxSumBST(struct TreeNode* root) {
    maxBSTSum = 0;
    checkBST(root);
    return maxBSTSum;
}
