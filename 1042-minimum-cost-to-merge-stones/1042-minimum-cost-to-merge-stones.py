class Solution:
    def mergeStones(self, stones, k):
        n = len(stones)
        if (n - 1) % (k - 1) != 0: return -1
        prefix = [0] * (len(stones) + 1)
        for i in range(len(stones)):
            prefix[i + 1] = prefix[i] + stones[i]
        dp = {}
        def dfs(i, j, m):
            if (i, j, m) in dp:
                return dp[(i, j, m)]
            if i == j:
                return 0 if m == 1 else float('inf')
            if m == 1:
                res = dfs(i, j, k) + prefix[j + 1] - prefix[i]
            else:
                res = float('inf')
                for p in range(i, j, k - 1):
                    res = min(res, dfs(i, p, 1) + dfs(p + 1, j, m - 1))
            dp[(i, j, m)] = res
            return res
        return dfs(0, n - 1, 1)
