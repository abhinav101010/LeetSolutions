class Solution:
    def alternatingSum(self, nums) :
        return sum(nums[0::2]) - sum(nums[1::2])
