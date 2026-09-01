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
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    int maxLevels = 2000;
    int** result = (int**)malloc(sizeof(int*) * maxLevels);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxLevels);
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int head = 0, tail = 0;
    queue[tail++] = root;
    bool leftToRight = true;

    while (head < tail) {
        int levelSize = tail - head;
        int* currentLevel = (int*)malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = node->val;
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        (*returnColumnSizes)[*returnSize] = levelSize;
        result[*returnSize] = currentLevel;
        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    free(queue);
    return result;
}
