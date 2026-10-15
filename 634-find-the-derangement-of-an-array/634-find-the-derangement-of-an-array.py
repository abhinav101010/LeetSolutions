class Solution:
    def findDerangement(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 0
        MOD = 10**9 + 7
        a, b = 1, 0  # D(0), D(1)
        for i in range(2, n+1):
            a, b = b, (i-1)*(a + b) % MOD
        return b
