class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        if not strs:
            return 0
        n = len(strs)
        m = len(strs[0])
        dp = [1]*m
        ans = 1
        for i in range(m):
            for j in range(i):
                ok = True
                for k in range(n):
                    if strs[k][j] > strs[k][i]:
                        ok = False
                        break
                if ok:
                    dp[i] = max(dp[i], dp[j]+1)
            ans = max(ans, dp[i])
        return m - ans
