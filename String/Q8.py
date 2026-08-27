class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        sign=0
        i=0
        res=0
        if not s:
            return 0

            
        if(s[0]=='-'):
            sign = -1
            i=1
        elif(s[0]=='+'):
            sign=1
            i=1
        else:
            sign=1
        while(i<len(s) and s[i].isdigit()):
            res=res*10 + int(s[i])
            i+=1
        res*=sign
        max=2**31 -1
        min=-2**31
        if(res>max):
            return max
        elif(res<min):
            return min
        return res
