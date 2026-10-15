class Solution:
    def sumSubseqWidths(self, A: list[int]) -> int:
        MOD = 10**9 + 7
        A.sort()
        n = len(A)
        pow2 = [1] * n
        for i in range(1, n):
            pow2[i] = (pow2[i-1] * 2) % MOD
        ans = 0
        for i, x in enumerate(A):
            left = pow2[i]          # 2^i
            right = pow2[n-1-i]     # 2^{n-1-i}
            ans = (ans + (left - right) * x) % MOD
        return ans
