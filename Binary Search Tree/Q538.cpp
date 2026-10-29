/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sumtree(TreeNode *root,int& total)
    {
        if(!root) return ;
        sumtree(root->right,total);
        total+=root->val;
        root->val=total;
        sumtree(root->left,total);
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        int total=0;
        sumtree(root,total);
        return root;    
    }
};
