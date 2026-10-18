class Solution:
    def minimumOperationsToMakeEqual(self, x, y):
        @cache
        def dfs(x):
            if y >= x:
                return y - x
            ans = x - y
            ans = min(ans, x % 5 + 1 + dfs(x // 5))
            ans = min(ans, 5 - x % 5 + 1 + dfs(x // 5 + 1))
            ans = min(ans, x % 11 + 1 + dfs(x // 11))
            ans = min(ans, 11 - x % 11 + 1 + dfs(x // 11 + 1))
            return ans

        return dfs(x)
