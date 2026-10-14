class Solution:
    def encode(self, s: str) -> str:
        n = len(s)
        dp = [["" for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = s[i]
        for length in range(2, n+1):
            for i in range(n - length + 1):
                j = i + length - 1
                substr = s[i:j+1]
                dp[i][j] = substr  # default no encoding
                # try splitting
                for k in range(i, j):
                    left = dp[i][k]
                    right = dp[k+1][j]
                    if len(left) + len(right) < len(dp[i][j]):
                        dp[i][j] = left + right
                # try to encode as repeated pattern
                # find the shortest pattern that repeats to form substr
                l = len(substr)
                for p in range(1, l//2 + 1):
                    if l % p == 0:
                        repeats = l // p
                        pattern = substr[:p]
                        if pattern * repeats == substr:
                            encoded = str(repeats) + '[' + dp[i][i+p-1] + ']'
                            if len(encoded) < len(dp[i][j]):
                                dp[i][j] = encoded
        return dp[0][n-1]
