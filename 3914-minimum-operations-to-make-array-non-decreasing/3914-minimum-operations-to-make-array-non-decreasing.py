class Solution:
    def minOperations(self, nums):
        return sum(max(a - b, 0) for a, b in pairwise(nums))
