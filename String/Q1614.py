class Solution:
    def maxDepth(self, s: str) -> int:
        result=0
        r=0
        for c in s:
            if(c=="("):
                r=r+1
            elif(c==")"):
                r=r-1
            result=max(result,r)
        return result
