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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        dfs(root, arr);
        sort(arr.begin(), arr.end());
        
        TreeNode* new_root = arrange(arr);
        return new_root;
    }
    
    void dfs(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }
        arr.push_back(root->val);
        dfs(root->left, arr);
        dfs(root->right, arr);
    }
    
    TreeNode* arrange(vector<int>& arr){
        if (arr.empty()) {
            return NULL;
        }
        TreeNode* new_root = new TreeNode(arr[0]);
        TreeNode* current = new_root;
        for(int i = 1; i < arr.size(); i++){
            current->right = new TreeNode(arr[i]);
            current->left = NULL;
            current = current->right;
        }
        return new_root;
    }
};
