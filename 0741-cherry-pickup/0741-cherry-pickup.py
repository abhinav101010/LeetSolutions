from typing import List
from functools import lru_cache

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        NEG_INF = -10**9
        @lru_cache(None)
        def dfs(r1, c1, r2):
            c2 = r1 + c1 - r2
            if r1 >= n or c1 >= n or r2 >= n or c2 >= n:
                return NEG_INF
            if grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return NEG_INF
            if r1 == n-1 and c1 == n-1:
                return grid[r1][c1]
            cherry = grid[r1][c1]
            if r1 != r2 or c1 != c2:
                cherry += grid[r2][c2]
            # next moves: both can go down or right
            best = NEG_INF
            for dr1 in [0, 1]:
                for dr2 in [0, 1]:
                    nr1 = r1 + dr1
                    nr2 = r2 + dr2
                    nc1 = c1 + dr1
                    nc2 = c2 + dr2
                    val = dfs(nr1, nc1, nr2)
                    if val > best:
                        best = val
            return best + cherry
        ans = dfs(0, 0, 0)
        return max(ans, 0)
