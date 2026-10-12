from functools import lru_cache

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 10**9 + 7
        
        @lru_cache(None)
        def dp(i, j, moves):
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1
            if moves == 0:
                return 0
            return (dp(i+1, j, moves-1) + dp(i-1, j, moves-1) + 
                    dp(i, j+1, moves-1) + dp(i, j-1, moves-1)) % MOD
        
        return dp(startRow, startColumn, maxMove)