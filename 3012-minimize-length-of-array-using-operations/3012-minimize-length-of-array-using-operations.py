class Solution:
    def minimumArrayLength(self, nums) :
        mi = min(nums)
        if any(x % mi for x in nums):
            return 1
        return (nums.count(mi) + 1) // 2
