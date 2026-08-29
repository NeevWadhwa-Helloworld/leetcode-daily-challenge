class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_v=0
        left=0
        right=len(height)-1
        while left<right:
            width=right-left
            h=min(height[left],height[right])
            max_v=max(max_v,h*width)

            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return max_v
