from functools import lru_cache
from typing import List

class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        @lru_cache(None)
        def dp(r, c, moves):
            if r < 0 or r >= n or c < 0 or c >= n:
                return 0
            if moves == 0:
                return 1
            dirs = [(-2,1),(-1,2),(1,2),(2,1),(2,-1),(1,-2),(-1,-2),(-2,-1)]
            res = 0
            for dr, dc_dir in dirs:
                res += dp(r+dr, c+dc_dir, moves-1)
            return res / 8
        return dp(row, column, k)