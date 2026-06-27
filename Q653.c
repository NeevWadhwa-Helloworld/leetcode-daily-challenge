/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void fillArray(struct TreeNode* root, int* arr, int* index) {
    if (!root) return;
    fillArray(root->left, arr, index);
    arr[(*index)++] = root->val;
    fillArray(root->right, arr, index);
}

bool findTarget(struct TreeNode* root, int k) {
    int n = countNodes(root);
    int* arr = (int*)malloc(sizeof(int) * n);
    int index = 0;
    
    fillArray(root, arr, &index);
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            free(arr);
            return true;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    free(arr);
    return false;
}
