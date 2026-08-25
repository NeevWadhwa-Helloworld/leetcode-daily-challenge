class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int i = 1;
        while (true) {
            int index = binarySearch(nums, k * i);
            if (index == -1) {
                return k * i;
            }
            i++;
        }
    }

    int binarySearch(const std::vector<int>& arr, int target) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
