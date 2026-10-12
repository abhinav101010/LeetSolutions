class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        res = 1
        count = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                count += 1
                res = max(res, count)
            else:
                count = 1
        return res