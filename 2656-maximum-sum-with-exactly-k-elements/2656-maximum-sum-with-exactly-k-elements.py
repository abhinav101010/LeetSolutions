class Solution:
    def maximizeSum(self, nums, k):
        x = max(nums)
        return k * x + k * (k - 1) // 2
