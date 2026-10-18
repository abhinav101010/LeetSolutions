class Solution:
    def paintWalls(self, cost, time):
        @cache
        def dfs(i, j):
            if n - i <= j:
                return 0
            if i >= n:
                return inf
            return min(dfs(i + 1, j + time[i]) + cost[i], dfs(i + 1, j - 1))

        n = len(cost)
        return dfs(0, 0)
