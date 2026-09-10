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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }

    std::pair<int,int> dfs(TreeNode* node,int& ans){
        if(!node){
            return {0,0};
        }
        std::pair<int, int> left = dfs(node->left, ans);
        int leftSum = left.first;
        int leftCount = left.second;

        std::pair<int, int> right = dfs(node->right, ans);
        int rightSum = right.first;
        int rightCount = right.second;

        int totalSum=node->val+leftSum+rightSum;
        int totalCount=1+rightCount+leftCount;

        if(totalSum/totalCount == node->val){
            ans++;
        }
        return {totalSum,totalCount};
    }
};
