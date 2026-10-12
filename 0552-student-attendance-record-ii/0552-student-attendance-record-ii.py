from functools import lru_cache

class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7
        
        @lru_cache(None)
        def dp(i, a, l):
            if i == n:
                return 1
            total = dp(i + 1, a, 0)  # P
            if a == 0:
                total = (total + dp(i + 1, 1, 0)) % MOD  # A
            if l < 2:
                total = (total + dp(i + 1, a, l + 1)) % MOD  # L
            return total
        
        return dp(0, 0, 0)