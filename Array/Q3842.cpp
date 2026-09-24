class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> isOn(101, false);
        for (int b : bulbs) {
            isOn[b] = !isOn[b];
        }
        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
