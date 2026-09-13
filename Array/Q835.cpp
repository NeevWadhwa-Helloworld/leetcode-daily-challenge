#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Step 1: Collect coordinates of all 1s in both matrices
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // Step 2: Frequency array for displacement vectors
        // Range of dr and dc is [-(n-1), n-1]. Adding offset 30 maps range to [1, 59].
        int count[61][61] = {0};
        int maxOverlap = 0;

        // Step 3: Compute displacement vector for every pair of 1s
        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1 + 30;
                int dc = c2 - c1 + 30;
                count[dr][dc]++;
                maxOverlap = max(maxOverlap, count[dr][dc]);
            }
        }

        return maxOverlap;
    }
};
