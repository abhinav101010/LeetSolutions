class Solution:
    def largestSumOfAverages(self, nums: list[int], k: int) -> float:
        n = len(nums)
        prefix = [0.0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
        # dp[i][k] = best score for first i elements using k groups
        dp = [[0.0] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[i][1] = prefix[i] / i
        for groups in range(2, k + 1):
            for i in range(groups, n + 1):
                # try last partition from j to i-1 where j >= groups-1
                best = 0.0
                for j in range(groups-1, i):
                    avg = (prefix[i] - prefix[j]) / (i - j)
                    val = dp[j][groups-1] + avg
                    if val > dp[i][groups]:
                        dp[i][groups] = val
        return dp[n][k]
