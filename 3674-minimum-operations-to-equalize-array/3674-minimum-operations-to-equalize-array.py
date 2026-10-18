class Solution:
    def minOperations(self, nums):
        return int(any(x != nums[0] for x in nums))
