class Solution:
    def bitwiseComplement(self, N):
        if N == 0: return 1
        res = 0
        x = N
        while x:
            res = res * 2 + 1
            x >>= 1
        return res ^ N
