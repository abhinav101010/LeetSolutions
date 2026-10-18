class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        n = len(flights)
        k = len(days[0]) if days else 0
        dp = [[-10**9] * n for _ in range(k + 1)]
        dp[0][0] = 0
        for week in range(1, k + 1):
            for city in range(n):
                dp[week][city] = dp[week - 1][city]
                for prev in range(n):
                    if flights[prev][city]:
                        dp[week][city] = max(dp[week][city], dp[week - 1][prev])
                dp[week][city] += days[city][week - 1]
        return max(dp[k][i] for i in range(n))
