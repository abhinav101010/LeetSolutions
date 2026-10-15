from typing import List

class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        n = len(flights)
        k = len(days[0])
        # dp[city][week]
        dp = [[-1]*k for _ in range(n)]
        # week 0
        for c in range(n):
            if c == 0 or flights[0][c] == 1:
                dp[c][0] = days[c][0]
        for w in range(1, k):
            for c in range(n):
                best = -1
                for pc in range(n):
                    if (pc == c or flights[pc][c] == 1) and dp[pc][w-1] != -1:
                        best = max(best, dp[pc][w-1] + days[c][w])
                dp[c][w] = best
        ans = 0
        for c in range(n):
            ans = max(ans, dp[c][k-1])
        return ans
