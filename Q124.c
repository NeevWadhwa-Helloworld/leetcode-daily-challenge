/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

int maxPathSumHelper(struct TreeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }
    int leftGain = maxPathSumHelper(root->left, maxSum);
    int rightGain = maxPathSumHelper(root->right, maxSum);
    int leftMax = max_int(leftGain, 0);
    int rightMax = max_int(rightGain, 0);
    int currentPathSum = root->val + leftMax + rightMax;
    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }
    return root->val + max_int(leftMax, rightMax);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}
