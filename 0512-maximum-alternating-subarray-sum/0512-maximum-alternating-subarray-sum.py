class Solution:
    def maxAlternatingSum(self, nums):
        ans = dp0 = dp1 = 0
        for x in nums:
            dp0, dp1 = max(dp0, dp1 + x), max(dp1, dp0 - x)
            ans = max(ans, dp0, dp1)
        return ans
