class Solution {
public:
    int m = INT_MAX;
    int prev = -1;
    
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL){
            return m;
        }
        
        getMinimumDifference(root->left);
        if(prev != -1){
            m = min(m, root->val - prev);
        }
        prev = root->val;
        
        getMinimumDifference(root->right);
        
        return m;
    }
};
