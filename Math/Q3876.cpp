class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        bool has_odd = false;
        bool has_even = false;

        for (int x : nums1) {
            if (x % 2 != 0) {
                has_odd = true;
                min_odd = std::min(min_odd, x);
            } else {
                has_even = true;
                min_even = std::min(min_even, x);
            }
        }
        if (!has_odd || !has_even) {
            return true;
        }
        return min_even > min_odd;
    }
};
