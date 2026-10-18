class Solution:
    def minOperations(self, nums, target):
        s = {x for x, y in zip(nums, target) if x != y}
        return len(s)
