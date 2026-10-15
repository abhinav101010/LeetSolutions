class Solution:
    def minFallingPathSum(self, A: list[list[int]]) -> int:
        n = len(A)
        dp = A[0][:]  # copy first row
        for r in range(1, n):
            new = [0] * n
            for c in range(n):
                best = dp[c]
                if c > 0:
                    best = min(best, dp[c-1])
                if c < n-1:
                    best = min(best, dp[c+1])
                new[c] = A[r][c] + best
            dp = new
        return min(dp)
