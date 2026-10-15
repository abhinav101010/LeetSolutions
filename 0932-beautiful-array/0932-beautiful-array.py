class Solution:
    def beautifulArray(self, N: int) -> list[int]:
        memo = {1: [1]}
        def solve(n):
            if n not in memo:
                odds = solve((n + 1) // 2)
                evens = solve(n // 2)
                memo[n] = [2 * x - 1 for x in odds] + [2 * x for x in evens]
            return memo[n]
        return solve(N)
