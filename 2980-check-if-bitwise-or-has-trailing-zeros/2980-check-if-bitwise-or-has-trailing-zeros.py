class Solution:
    def hasTrailingZeros(self, nums) :
        return sum(x & 1 ^ 1 for x in nums) >= 2
