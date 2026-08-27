class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int best_i = -1;
        char best_char = ' ';
        vector<int> rem_count = count;
        for (int i = 0; i < n; ++i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (rem_count[c] > 0) {
                    best_i = i;
                    best_char = (char)('a' + c);
                    break;
                }
            }
            if (rem_count[target[i] - 'a'] > 0) {
                rem_count[target[i] - 'a']--;
            } else {
                break;
            }
        }
        if (best_i == -1) {
            return "";
        }
        string result = "";
        result.reserve(n);
        for (int i = 0; i < best_i; ++i) {
            result.push_back(target[i]);
            count[target[i] - 'a']--;
        }
        result.push_back(best_char);
        count[best_char - 'a']--;
        for (int c = 0; c < 26; ++c) {
            while (count[c] > 0) {
                result.push_back((char)('a' + c));
                count[c]--;
            }
        }

        return result;
    }
};
