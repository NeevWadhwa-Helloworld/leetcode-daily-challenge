typedef struct {
    int children[2];
} TrieNode;

typedef struct {
    int x;
    int m;
    int original_idx;
} QueryInfo;

TrieNode triePool[3000005];
int nodeCount = 0;

int createNode() {
    triePool[nodeCount].children[0] = -1;
    triePool[nodeCount].children[1] = -1;
    return nodeCount++;
}

void insert(int root, int num) {
    int curr = root;
    for (int i = 29; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (triePool[curr].children[bit] == -1) {
            triePool[curr].children[bit] = createNode();
        }
        curr = triePool[curr].children[bit];
    }
}

int getMaxXor(int root, int num) {
    int curr = root;
    int maxXor = 0;
    for (int i = 29; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int toggledBit = bit ^ 1;
        
        if (triePool[curr].children[toggledBit] != -1) {
            maxXor |= (1 << i);
            curr = triePool[curr].children[toggledBit];
        } else {
            curr = triePool[curr].children[bit];
        }
    }
    return maxXor;
}

int cmpNum(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    return (valA > valB) - (valA < valB);
}

int cmpQuery(const void* a, const void* b) {
    int valA = ((QueryInfo*)a)->m;
    int valB = ((QueryInfo*)b)->m;
    return (valA > valB) - (valA < valB);
}

int* maximizeXor(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    nodeCount = 0;
    int root = createNode();
    
    qsort(nums, numsSize, sizeof(int), cmpNum);
    
    QueryInfo* qInfo = (QueryInfo*)malloc(queriesSize * sizeof(QueryInfo));
    for (int i = 0; i < queriesSize; i++) {
        qInfo[i].x = queries[i][0];
        qInfo[i].m = queries[i][1];
        qInfo[i].original_idx = i;
    }
    qsort(qInfo, queriesSize, sizeof(QueryInfo), cmpQuery);
    
    int numsIdx = 0;
    for (int i = 0; i < queriesSize; i++) {
        int x = qInfo[i].x;
        int m = qInfo[i].m;
        int original_idx = qInfo[i].original_idx;
        
        while (numsIdx < numsSize && nums[numsIdx] <= m) {
            insert(root, nums[numsIdx]);
            numsIdx++;
        }
        
        if (numsIdx == 0) {
            ans[original_idx] = -1;
        } else {
            ans[original_idx] = getMaxXor(root, x);
        }
    }
    
    free(qInfo);
    return ans;
}
