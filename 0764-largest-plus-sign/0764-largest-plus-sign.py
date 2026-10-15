from typing import List

class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        # Initialize dp with n (max possible)
        dp = [[n] * n for _ in range(n)]
        # Set mines to 0
        for x, y in mines:
            dp[x][y] = 0
        # Left to right
        for i in range(n):
            cnt = 0
            for j in range(n):
                if dp[i][j] == 0:
                    cnt = 0
                else:
                    cnt += 1
                dp[i][j] = min(dp[i][j], cnt)
        # Right to left
        for i in range(n):
            cnt = 0
            for j in range(n-1, -1, -1):
                if dp[i][j] == 0:
                    cnt = 0
                else:
                    cnt += 1
                dp[i][j] = min(dp[i][j], cnt)
        # Top to bottom
        for j in range(n):
            cnt = 0
            for i in range(n):
                if dp[i][j] == 0:
                    cnt = 0
                else:
                    cnt += 1
                dp[i][j] = min(dp[i][j], cnt)
        # Bottom to top
        for j in range(n):
            cnt = 0
            for i in range(n-1, -1, -1):
                if dp[i][j] == 0:
                    cnt = 0
                else:
                    cnt += 1
                dp[i][j] = min(dp[i][j], cnt)
        # Find max
        ans = 0
        for i in range(n):
            for j in range(n):
                ans = max(ans, dp[i][j])
        return ans
