class Solution:
    def minMoves(self, nums):
        n = len(nums)
        mx = max(nums)
        s = sum(nums)
        return mx * n - s
