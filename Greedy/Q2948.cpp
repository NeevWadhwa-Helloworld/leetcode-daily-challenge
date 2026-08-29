class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<deque<int>> groups;
        unordered_map<int, int> num_to_group;
        num_to_group.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (i == 0 || sorted_nums[i] - sorted_nums[i - 1] > limit) {
                groups.push_back(deque<int>());
            }
            groups.back().push_back(sorted_nums[i]);
            num_to_group[sorted_nums[i]] = groups.size() - 1;
        }
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int group_id = num_to_group[nums[i]];
            result[i] = groups[group_id].front();
            groups[group_id].pop_front();
        }

        return result;
    }
};
