class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        num3=nums1+nums2
        for i in range(len(num3)):
            for j in range(len(num3)-1):
                if(num3[j]>num3[j+1]):
                    temp=num3[j]
                    num3[j]=num3[j+1]
                    num3[j+1]=temp
        if(len(num3)%2==0):
            m=float((num3[len(num3)//2]+num3[(len(num3)//2)-1])/2.0)
            
        else:
            m=num3[len(num3)//2]
        return m
