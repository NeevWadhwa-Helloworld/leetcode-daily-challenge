class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_suffix(n);
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(nums[i], min_suffix[i + 1]);
        }
        int max_prefix = nums[0];
        for (int i = 0; i < n; ++i) {
            max_prefix = max(max_prefix, nums[i]);
            int instability_score = max_prefix - min_suffix[i];
            
            if (instability_score <= k) {
                return i;
            }
        }
        
        return -1;
    }
};
