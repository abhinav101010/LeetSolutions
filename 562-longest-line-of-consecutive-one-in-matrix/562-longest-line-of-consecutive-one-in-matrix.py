from typing import List

class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        if not M or not M[0]:
            return 0
        rows, cols = len(M), len(M[0])
        # dp[rows][cols][4] where 0:horizontal,1:vertical,2:diagonal,3:anti-diagonal
        dp = [[[0]*4 for _ in range(cols)] for _ in range(rows)]
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if M[i][j] == 1:
                    dp[i][j][0] = (dp[i][j-1][0] if j>0 else 0) + 1
                    dp[i][j][1] = (dp[i-1][j][1] if i>0 else 0) + 1
                    dp[i][j][2] = (dp[i-1][j-1][2] if i>0 and j>0 else 0) + 1
                    dp[i][j][3] = (dp[i-1][j+1][3] if i>0 and j+1<cols else 0) + 1
                    ans = max(ans, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3])
        return ans
