from functools import lru_cache
class Solution:
    def assignBikes(self, workers, bikes):
        n, m = len(workers), len(bikes)
        @lru_cache(None)
        def dp(i, mask):
            if i == n:
                return 0
            best = float('inf')
            for j in range(m):
                if mask >> j & 1:
                    continue
                dist = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1])
                best = min(best, dist + dp(i+1, mask | (1<<j)))
            return best
        return dp(0, 0)
