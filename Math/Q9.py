class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        sign=1
        if(x<0):
            sign=-1
            x= -x
        
        s=str(x)
        r=s[::-1]
        rx=int(r)
        rx=rx*sign
        if(x==rx):
            return True
        else:
            return False
