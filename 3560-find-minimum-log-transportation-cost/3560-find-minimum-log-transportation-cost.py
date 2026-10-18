class Solution:
    def minCuttingCost(self, n, m, k):
        x = max(n, m)
        return 0 if x <= k else k * (x - k)
