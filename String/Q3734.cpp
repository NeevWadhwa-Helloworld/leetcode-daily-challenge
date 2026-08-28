class Solution {
public:
    std::string lexPalindromicPermutation(std::string s, std::string target) {
        int n = s.length();
        int m = n / 2;
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        
        if (n % 2 == 0 && odd_count > 0) return "";
        if (n % 2 != 0 && odd_count != 1) return "";
        std::vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = freq[i] / 2;
        }
        std::vector<int> target_prefix_count(26, 0);
        int L = 0;
        while (L < m) {
            int ch = target[L] - 'a';
            if (target_prefix_count[ch] + 1 <= half_count[ch]) {
                target_prefix_count[ch]++;
                L++;
            } else {
                break;
            }
        }        for (int k = L; k >= 0; --k) {
            if (k < L) {
                target_prefix_count[target[k] - 'a']--;
            }
            std::vector<int> rem_counts(26, 0);
            for (int i = 0; i < 26; ++i) {
                rem_counts[i] = half_count[i] - target_prefix_count[i];
            }
            
            if (k == m) {
                std::string left = target.substr(0, m);
                std::string full = left;
                if (n % 2 != 0) full += mid_char;
                std::string right = left;
                std::reverse(right.begin(), right.end());
                full += right;
                
                if (full > target) {
                    return full;
                }
            } else {
                int target_ch = target[k] - 'a';
                int chosen_c = -1;
                for (int c = target_ch + 1; c < 26; ++c) {
                    if (rem_counts[c] > 0) {
                        chosen_c = c;
                        break;
                    }
                }
                
                if (chosen_c != -1) {
                    std::string left = target.substr(0, k);
                    left += (char)('a' + chosen_c);
                    rem_counts[chosen_c]--;
                    for (int c = 0; c < 26; ++c) {
                        left.append(rem_counts[c], (char)('a' + c));
                    }
                    
                    std::string full = left;
                    if (n % 2 != 0) full += mid_char;
                    std::string right = left;
                    std::reverse(right.begin(), right.end());
                    full += right;
                    
                    return full;
                }
            }
        }
        
        return "";
    }
};
