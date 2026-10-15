class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7
        if n == 0:
            return 1
        if n == 1:
            return 1
        dp = [0] * (n + 1)
        g = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        g[0] = 0
        g[1] = 1
        for i in range(2, n + 1):
            dp[i] = (dp[i-1] + dp[i-2] + 2 * g[i-2]) % MOD
            g[i] = (g[i-1] + dp[i-1]) % MOD
        return dp[n]
