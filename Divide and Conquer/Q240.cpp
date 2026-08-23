class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (const auto& row : matrix) {
            if (row.front() <= target && target <= row.back()) {
                if (binarySearchRow(row, target) != -1) {
                    return true;
                }
            }
        }
        return false;
    }

    int binarySearchRow(const vector<int>& row, int target) {
        int low = 0;
        int high = row.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == target) {
                return mid;
            } else if (row[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
