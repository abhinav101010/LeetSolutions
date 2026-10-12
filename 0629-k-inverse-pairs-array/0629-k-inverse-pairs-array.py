class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9 + 7
        dp = [0] * (k + 1)
        dp[0] = 1
        
        for i in range(1, n + 1):
            next_dp = [0] * (k + 1)
            for j in range(k + 1):
                if dp[j] == 0:
                    continue
                for x in range(min(j + 1, i)):
                    next_dp[j - x] = (next_dp[j - x] + dp[j]) % MOD
            dp = next_dp
        
        return dp[0] if k >= 0 else 0