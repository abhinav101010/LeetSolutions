class Solution:
    def minimumAverage(self, nums):
        nums.sort()
        n = len(nums)
        return min(nums[i] + nums[-i - 1] for i in range(n // 2)) / 2
