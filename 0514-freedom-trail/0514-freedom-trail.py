from functools import lru_cache

class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        @lru_cache(None)
        def dp(i, j):
            if j == len(key):
                return 0
            min_steps = float('inf')
            for k, ch in enumerate(ring):
                if ch == key[j]:
                    diff = abs(k - i)
                    steps = min(diff, len(ring) - diff) + 1
                    min_steps = min(min_steps, steps + dp(k, j + 1))
            return min_steps
        
        return dp(0, 0)