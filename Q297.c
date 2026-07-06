/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void serializeHelper(struct TreeNode* root, char* str, int* len) {
    if (root == NULL) {
        *len += sprintf(str + *len, "#,");
        return;
    }
    *len += sprintf(str + *len, "%d,", root->val);
    serializeHelper(root->left, str, len);
    serializeHelper(root->right, str, len);
}
char* serialize(struct TreeNode* root) {
    char* str = (char*)malloc(sizeof(char) * 500000);
    int len = 0;
    str[0] = '\0';
    
    serializeHelper(root, str, &len);
    return str;
}
struct TreeNode* deserializeHelper(char** strRef) {
    char* token = strsep(strRef, ",");
    if (token == NULL || strcmp(token, "#") == 0 || strcmp(token, "") == 0) {
        return NULL;
    }
    struct TreeNode* root = createNode(atoi(token));
    root->left = deserializeHelper(strRef);
    root->right = deserializeHelper(strRef);
    
    return root;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (data == NULL || strlen(data) == 0) {
        return NULL;
    }
    
    // strsep modifies the original pointer, so we pass a copy reference
    char* dataCopy = data; 
    return deserializeHelper(&dataCopy);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
