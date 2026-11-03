class Solution:
    def minMoves(self, nums: List[int]) -> int:
        M=-10000
        for num in nums:
            if(M<num):
                M=num
        moves=0
        for num in nums:
            moves+=(M-num)
        return moves
