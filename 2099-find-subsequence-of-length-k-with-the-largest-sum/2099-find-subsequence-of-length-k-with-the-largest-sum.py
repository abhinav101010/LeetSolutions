class Solution:
    def maxSubsequence(self, nums, k):
        idx = sorted(range(len(nums)), key=lambda i: nums[i])[-k:]
        return [nums[i] for i in sorted(idx)]