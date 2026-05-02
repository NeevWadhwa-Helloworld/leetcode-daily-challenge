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

int countNodes(struct TreeNode* root){
    if(root==NULL) return 0;
    return 1+ countNodes(root->left)+ countNodes(root->right);
}

void traverse(struct TreeNode* root, int* res, int* returnSize){
    if(root==NULL) return;
    res[(*returnSize)++]=root->val;
    traverse(root->left,res,returnSize);
    traverse(root->right,res,returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int totalNodes=countNodes(root);
    int* res=(int*)malloc(sizeof(int)*totalNodes);
    *returnSize=0;
    traverse(root,res,returnSize);
    return res;
}
