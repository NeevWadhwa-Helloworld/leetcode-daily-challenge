int trie[6200000][2];
int nodeCount;
void initTrie() {
    memset(trie[0], 0, sizeof(trie[0]));
    nodeCount = 1;
}
void insert(int num) {
    int curr = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (trie[curr][bit] == 0) {
            trie[nodeCount][0] = 0;
            trie[nodeCount][1] = 0;
            trie[curr][bit] = nodeCount++;
        }
        curr = trie[curr][bit];
    }
}

int getMaxXOR(int num) {
    int curr = 0;
    int maxXOR = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int toggledBit = bit ^ 1;
        if (trie[curr][toggledBit] != 0) {
            maxXOR |= (1 << i);
            curr = trie[curr][toggledBit];
        } else {
            curr = trie[curr][bit];
        }
    }
    return maxXOR;
}

int findMaximumXOR(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    initTrie();
    int maxResult = 0;
    insert(nums[0]);
    for (int i = 1; i < numsSize; i++) {
        int currentMax = getMaxXOR(nums[i]);
        if (currentMax > maxResult) {
            maxResult = currentMax;
        }
        insert(nums[i]);
    }
    
    return maxResult;
}
