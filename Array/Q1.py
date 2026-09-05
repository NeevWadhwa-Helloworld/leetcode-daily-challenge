class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        for i in range(0,len(nums),1):
            for j in range(0,len(nums),1):
                if(i==j):
                    continue
                else:
                    sum=nums[i]+nums[j]
                    if(sum==target):
                        ind=[i,j]
                        return ind
                    else:
                        continue
