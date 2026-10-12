class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        # n = len(nums)
        # if n < 2: return 0
        nums.sort()
        ans = 0
        for i in range(len(nums)-1):
            ans = max(ans, nums[i+1]-nums[i])
        return ans