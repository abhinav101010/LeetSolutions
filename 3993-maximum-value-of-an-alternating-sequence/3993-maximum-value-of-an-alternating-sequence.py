class Solution:
    def maximumValue(self, n, s, m) :
        if n == 1:
            return s
        return s + n // 2 * (m - 1) + 1
