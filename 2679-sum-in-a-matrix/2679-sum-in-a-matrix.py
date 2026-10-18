class Solution:
    def matrixSum(self, nums):
        for row in nums:
            row.sort()
        return sum(map(max, zip(*nums)))