/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int maxLevels = 2000; 
    int** result = (int**)malloc(sizeof(int*) * maxLevels);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxLevels);
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head; 
        int* currentLevel = (int*)malloc(sizeof(int) * levelSize);
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            currentLevel[i] = node->val;

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }

        (*returnColumnSizes)[*returnSize] = levelSize;
        result[(*returnSize)++] = currentLevel;
    }

    free(queue);
    return result;
}
