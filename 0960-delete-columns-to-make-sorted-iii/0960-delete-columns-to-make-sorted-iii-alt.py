class Solution:
    def minDeletionSize(self, strs):
        m = len(strs[0])
        n = len(strs)
        dp = [1]*m
        for i in range(m):
            for j in range(i):
                ok = True
                for k in range(n):
                    if strs[k][j] > strs[k][i]:
                        ok = False
                        break
                if ok:
                    dp[i] = max(dp[i], dp[j] + 1)
        return m - max(dp) if dp else 0
