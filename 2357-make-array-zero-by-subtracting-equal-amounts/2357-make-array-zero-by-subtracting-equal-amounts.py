class Solution:
    def minimumOperations(self, nums):
        return len({x for x in nums if x})
