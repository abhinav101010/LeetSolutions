class Solution:
    def minEnd(self, n, x):
        n -= 1
        ans = x
        for i in range(31):
            if x >> i & 1 ^ 1:
                ans |= (n & 1) << i
                n >>= 1
        ans |= n << 31
        return ans
