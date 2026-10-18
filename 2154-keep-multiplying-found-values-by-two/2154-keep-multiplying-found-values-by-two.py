class Solution:
    def findFinalValue(self, nums, original):
        s = set(nums)
        while original in s:
            original <<= 1
        return original