class Solution:
    def circularPermutation(self, n, start) :
        g = [i ^ (i >> 1) for i in range(1 << n)]
        j = g.index(start)
        return g[j:] + g[:j]
