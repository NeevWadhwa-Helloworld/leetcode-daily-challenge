class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string result = "";
        string key = "";
        bool insideBracket = false;
        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
            } else if (c == ')') {
                insideBracket = false;
                if (mp.find(key) != mp.end()) {
                    result += mp[key];
                } else {
                    result += '?';
                }
                key = ""; 
            } else if (insideBracket) {
                key += c;
            } else {
                result += c;
            }
        }

        return result;
    }
};
