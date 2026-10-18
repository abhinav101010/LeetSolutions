class Solution:
    def maxScore(self, a, b):
        @cache
        def dfs(i, j):
            if j >= len(b):
                return 0 if i >= len(a) else -inf
            if i >= len(a):
                return 0
            return max(dfs(i, j + 1), a[i] * b[j] + dfs(i + 1, j + 1))

        return dfs(0, 0)
