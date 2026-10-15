class Solution:
    def maxA(self, n: int) -> int:
        if n <= 6:
            return n
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = i  # just press A i times
        for i in range(7, n + 1):
            for j in range(i - 3, 0, -1):
                dp[i] = max(dp[i], dp[j] * (i - j - 1))
        return dp[n]
