class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1: return nums[0]

        prev2 = 0
        prev1 = 0
        for money in nums[1:]:
            curr = max(prev1, prev2 + money)
            prev2 = prev1
            prev1 = curr

        ans = prev1

        prev2 = 0
        prev1 = 0
        for money in nums[:-1]:
            curr = max(prev1, prev2 + money)
            prev2 = prev1
            prev1 = curr

        return max(prev1, ans) 