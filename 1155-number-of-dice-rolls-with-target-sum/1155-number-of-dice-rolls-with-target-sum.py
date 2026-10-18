class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 10**9 + 7
        f = [0] * (target + 1)
        f[0] = 1
        for _ in range(n):
            g = [0] * (target + 1)
            for j in range(1, target + 1):
                for h in range(1, k + 1):
                    if j - h >= 0:
                        g[j] = (g[j] + f[j - h]) % MOD
            f = g
        return f[target]
