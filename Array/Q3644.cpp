class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            result = result & nums[i];
        }
        return result == INT_MAX ? 0 : result;
    }
};
