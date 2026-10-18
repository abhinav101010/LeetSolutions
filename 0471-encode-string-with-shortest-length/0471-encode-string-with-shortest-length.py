class Solution:
    def encode(self, s: str) -> str:
        n = len(s)
        dp = [[''] * n for _ in range(n)]
        for length in range(1, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = s[i : j + 1]
                if length > 4:
                    for k in range(i, j):
                        mid = k - i + 1
                        if length % mid == 0:
                            pattern = s[i : i + mid]
                            is_repeated = True
                            for t in range(1, length // mid):
                                if s[i + t * mid : i + t * mid + mid] != pattern:
                                    is_repeated = False
                                    break
                            if is_repeated:
                                candidate = str(length // mid) + '[' + dp[i][k] + ']'
                                if len(candidate) < len(dp[i][j]):
                                    dp[i][j] = candidate
                    for k in range(i, j):
                        if len(dp[i][k]) + len(dp[k + 1][j]) < len(dp[i][j]):
                            dp[i][j] = dp[i][k] + dp[k + 1][j]
        return dp[0][n - 1]
