class Solution:
    def isArmstrong(self, n):
        s=str(n); p=len(s)
        return n==sum(int(d)**p for d in s)
