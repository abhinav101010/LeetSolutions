from functools import lru_cache

class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger * (maxChoosableInteger + 1) // 2 < desiredTotal:
            return False
        if desiredTotal <= 0:
            return True
        
        @lru_cache(None)
        def dfs(used, total):
            for i in range(1, maxChoosableInteger + 1):
                if not (used & (1 << i)):
                    if total + i >= desiredTotal or not dfs(used | (1 << i), total + i):
                        return True
            return False
        
        return dfs(0, 0)