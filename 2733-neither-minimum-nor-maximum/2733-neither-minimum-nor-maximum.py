class Solution:
    def findNonMinOrMax(self, nums):
        mi, mx = min(nums), max(nums)
        return next((x for x in nums if x != mi and x != mx), -1)
