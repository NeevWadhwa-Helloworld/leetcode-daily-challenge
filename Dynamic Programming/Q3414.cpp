#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct State {
        long long weight = -1e18;
        vector<int> indices;
    };

    bool isBetter(const State& a, const State& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        return a.indices < b.indices;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(A.begin(), A.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id;
        });

        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Base cases at index n
        dp[n][0].weight = 0;
        dp[n][0].indices = {};
        for (int k = 1; k <= 4; ++k) {
            dp[n][k].weight = -1e18;
            dp[n][k].indices = {};
        }

        for (int i = n - 1; i >= 0; --i) {
            dp[i][0].weight = 0;
            dp[i][0].indices = {};

            long long target_l = (long long)A[i].r + 1;
            auto it = lower_bound(A.begin() + i + 1, A.end(), target_l,
                [](const Interval& a, long long val) {
                    return a.l < val;
                });
            int next_idx = distance(A.begin(), it);

            for (int k = 1; k <= 4; ++k) {

                State best_state = dp[i + 1][k];

                if (dp[next_idx][k - 1].weight > -1e17) {
                    State take_state;
                    take_state.weight = (long long)A[i].weight + dp[next_idx][k - 1].weight;
                    take_state.indices = dp[next_idx][k - 1].indices;
                    take_state.indices.push_back(A[i].id);
                    sort(take_state.indices.begin(), take_state.indices.end());

                    if (isBetter(take_state, best_state)) {
                        best_state = take_state;
                    }
                }

                dp[i][k] = best_state;
            }
        }

        State ans = dp[0][0];
        for (int k = 1; k <= 4; ++k) {
            if (isBetter(dp[0][k], ans)) {
                ans = dp[0][k];
            }
        }

        return ans.indices;
    }
};
