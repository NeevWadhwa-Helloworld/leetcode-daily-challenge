class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return divideAndConquer(buildings, 0, buildings.size() - 1);
    }

    vector<vector<int>> divideAndConquer(const vector<vector<int>>& buildings, int start, int end) {
        if (start == end) {
            int L = buildings[start][0];
            int R = buildings[start][1];
            int H = buildings[start][2];
            return {{L, H}, {R, 0}};
        }

        int mid = start + (end - start) / 2;
        vector<vector<int>> leftSkyline = divideAndConquer(buildings, start, mid);
        vector<vector<int>> rightSkyline = divideAndConquer(buildings, mid + 1, end);

        return merge(leftSkyline, rightSkyline);
    }

    vector<vector<int>> merge(const vector<vector<int>>& left, const vector<vector<int>>& right) {
        int i = 0, j = 0;
        int h1 = 0, h2 = 0;
        vector<vector<int>> merged;

        while (i < left.size() && j < right.size()) {
            int x;
            if (left[i][0] < right[j][0]) {
                x = left[i][0];
                h1 = left[i][1];
                i++;
            } else if (right[j][0] < left[i][0]) {
                x = right[j][0];
                h2 = right[j][1];
                j++;
            } else {
                x = left[i][0];
                h1 = left[i][1];
                h2 = right[j][1];
                i++;
                j++;
            }

            int maxH = max(h1, h2);
            if (merged.empty() || merged.back()[1] != maxH) {
                merged.push_back({x, maxH});
            }
        }
        while (i < left.size()) {
            int x = left[i][0];
            h1 = left[i][1];
            int maxH = max(h1, h2);
            if (merged.empty() || merged.back()[1] != maxH) {
                merged.push_back({x, maxH});
            }
            i++;
        }
        while (j < right.size()) {
            int x = right[j][0];
            h2 = right[j][1];
            int maxH = max(h1, h2);
            if (merged.empty() || merged.back()[1] != maxH) {
                merged.push_back({x, maxH});
            }
            j++;
        }

        return merged;
    }
};
