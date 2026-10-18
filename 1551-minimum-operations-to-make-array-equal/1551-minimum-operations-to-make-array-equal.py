class Solution:
    def minOperations(self, n):
        return sum(n - (i << 1 | 1) for i in range(n >> 1))