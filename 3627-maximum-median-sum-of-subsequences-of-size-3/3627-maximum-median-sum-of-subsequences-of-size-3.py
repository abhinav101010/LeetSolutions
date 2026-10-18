class Solution:
    def maximumMedianSum(self, nums) :
        nums.sort()
        return sum(nums[len(nums) // 3 :: 2])
