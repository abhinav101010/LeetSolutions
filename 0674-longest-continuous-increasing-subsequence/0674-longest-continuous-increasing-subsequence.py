class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        ans = 0
        curr = 0
        for i in range(len(nums)):
            if i>0 and nums[i]>nums[i-1]:
                curr+=1
            else:
                ans = max(ans, curr)
                curr = 1
        return max(ans, curr)