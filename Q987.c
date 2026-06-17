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
typedef struct {
    int col;
    int row;
    int val;
} NodeInfo;

int compareNodes(const void *a, const void *b) {
    NodeInfo *nodeA = (NodeInfo *)a;
    NodeInfo *nodeB = (NodeInfo *)b;
    if (nodeA->col != nodeB->col) {
        return nodeA->col - nodeB->col;
    }
    if (nodeA->row != nodeB->row) {
        return nodeA->row - nodeB->row;
    }
    return nodeA->val - nodeB->val;
}

void collectNodes(struct TreeNode* root, int row, int col, NodeInfo* elements, int* count) {
    if (root == NULL) return;
    
    elements[*count].row = row;
    elements[*count].col = col;
    elements[*count].val = root->val;
    (*count)++;
    
    collectNodes(root->left, row + 1, col - 1, elements, count);
    collectNodes(root->right, row + 1, col + 1, elements, count);
}

int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    NodeInfo* elements = (NodeInfo*)malloc(2000 * sizeof(NodeInfo));
    int nodeCount = 0;
    collectNodes(root, 0, 0, elements, &nodeCount);
    qsort(elements, nodeCount, sizeof(NodeInfo), compareNodes);
    int uniqueCols = 0;
    for (int i = 0; i < nodeCount; i++) {
        if (i == 0 || elements[i].col != elements[i - 1].col) {
            uniqueCols++;
        }
    }
    int** result = (int**)malloc(uniqueCols * sizeof(int*));
    *returnColumnSizes = (int*)malloc(uniqueCols * sizeof(int));
    *returnSize = uniqueCols;
    
    int colIndex = -1;
    int segmentStart = 0;
    
    for (int i = 0; i <= nodeCount; i++) {
        if (i == nodeCount || (i > 0 && elements[i].col != elements[i - 1].col)) {
            int segmentLen = i - segmentStart;
            
            result[colIndex] = (int*)malloc(segmentLen * sizeof(int));
            (*returnColumnSizes)[colIndex] = segmentLen;
            
            for (int j = 0; j < segmentLen; j++) {
                result[colIndex][j] = elements[segmentStart + j].val;
            }
            
            segmentStart = i;
        }
        
        if (i < nodeCount && (i == 0 || elements[i].col != elements[i - 1].col)) {
            colIndex++;
        }
    }
    
    free(elements);
    return result;
}
