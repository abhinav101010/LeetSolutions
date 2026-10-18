class Solution:
    def numberOfCuts(self, n):
        return n if (n > 1 and n & 1) else n >> 1
