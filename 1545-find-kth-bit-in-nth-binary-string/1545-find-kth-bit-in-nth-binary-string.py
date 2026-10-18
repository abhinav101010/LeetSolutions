class Solution:
    def findKthBit(self, n, k):
        def dfs(n, k):
            if k == 1:
                return 0
            if (k & (k - 1)) == 0:
                return 1
            m = 1 << n
            if k * 2 < m - 1:
                return dfs(n - 1, k)
            return dfs(n - 1, m - k) ^ 1

        return str(dfs(n, k))
