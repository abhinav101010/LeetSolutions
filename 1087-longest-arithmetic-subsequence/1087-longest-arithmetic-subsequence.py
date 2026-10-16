class Solution:
    def longestArithSeqLength(self, nums):
        n = len(nums)
        dp = [{} for _ in range(n)]
        ans = 0
        for j in range(n):
            for i in range(j):
                d = nums[j] - nums[i]
                dp[j][d] = dp[i].get(d, 1) + 1
                ans = max(ans, dp[j][d])
        return ans
