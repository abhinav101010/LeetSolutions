class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        total = 0
        max_ending = max_best = nums[0]
        min_ending = min_best = nums[0]
        for x in nums:
            max_ending = max(x, max_ending + x)
            max_best = max(max_best, max_ending)
            min_ending = min(x, min_ending + x)
            min_best = min(min_best, min_ending)
            total += x
        if max_best < 0:
            return max_best
        return max(max_best, total - min_best)
