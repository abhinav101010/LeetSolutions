class Solution:
    def maxAdjacentDistance(self, nums):
        return max(abs(a - b) for a, b in pairwise(nums + [nums[0]]))
