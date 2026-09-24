class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for (int num : nums) {
            nums_map[num]++;
        }

        vector<int> new_nums;
        for (auto& pair : nums_map) {
            if (pair.second == 3) {
                new_nums.push_back(pair.first);
            }
        }

        int count = 0;
        for (int i = 0; i < new_nums.size(); i++) {
            vector<int> idx;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == new_nums[i]) {
                    idx.push_back(j);
                }
            }
            if (idx[1] - idx[0] == idx[2] - idx[1]) {
                count++;
            }
        }

        return count;
    }
};
