class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        long long S = 0;
        for (int x : stones) S += x;

        long long ans = S;
        for (int i = n - 1; i >= 2; --i) {
            S -= stones[i];
            ans = max(ans, S - ans);
        }
        return ans;
    }
};
