/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef unsigned long long ULL;

typedef struct {
    struct TreeNode* node;
    ULL index;
} Pair;

int widthOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) return 0;

    Pair queue[3000];
    int front = 0, rear = 0;

    queue[rear++] = (Pair){root, 0};

    int maxWidth = 0;

    while (front < rear) {
        int size = rear - front;

        ULL minIndex = queue[front].index;
        ULL first = 0, last = 0;

        for (int i = 0; i < size; i++) {
            Pair current = queue[front++];

            ULL currIndex = current.index - minIndex;

            if (i == 0) first = currIndex;
            if (i == size - 1) last = currIndex;

            if (current.node->left)
                queue[rear++] =
                    (Pair){current.node->left, 2 * currIndex + 1};

            if (current.node->right)
                queue[rear++] =
                    (Pair){current.node->right, 2 * currIndex + 2};
        }

        int width = (int)(last - first + 1);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}
