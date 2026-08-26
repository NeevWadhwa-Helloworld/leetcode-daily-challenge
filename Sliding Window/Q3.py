class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_map={}
        max_length=0
        start=0
        for end in range(len(s)):
            if s[end] in char_map and char_map[s[end]] >= start:
                start=char_map[s[end]]+1
            char_map[s[end]]=end
            current_len=end-start+1
            if (max_length < current_len):
                max_length=current_len
        return max_length
