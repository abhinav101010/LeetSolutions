class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        from functools import lru_cache
        import math
        @lru_cache(None)
        def dfs(t):
            if t == 0:
                return 0
            if t < x:
                return min(2*t - 1, 2*(x - t))
            k = int(math.log(t, x))
            p = x**k
            ans1 = float('inf')
            if p <= t:
                ans1 = k + dfs(t - p)
            p2 = x**(k+1)
            ans2 = float('inf')
            if p2 - t < t:
                ans2 = (k+1) + dfs(p2 - t)
            return min(ans1, ans2)
        return dfs(target)
