class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        f=0
        sign=0
        if(x<0):
            x=-x
            sign=1
        

        while(x>0):
            digit=x%10
            x=x//10
            f=(f*10)+digit
        if(sign==1):
            f=-f

        if((f>2147483647)or(f<-2147483648)):
            return 0
        else:
            return f
