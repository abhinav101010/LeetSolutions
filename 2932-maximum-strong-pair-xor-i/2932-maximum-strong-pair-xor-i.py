class Solution:
    def maximumStrongPairXor(self, nums) :
        return max(x ^ y for x in nums for y in nums if abs(x - y) <= min(x, y))
