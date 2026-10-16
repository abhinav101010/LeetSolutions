class Solution:
    def isArmstrong(self, N):
        s = str(N)
        k = len(s)
        return sum(int(c)**k for c in s) == N
