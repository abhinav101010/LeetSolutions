class Solution:
    def isReachable(self, targetX, targetY) :
        x = gcd(targetX, targetY)
        return x & (x - 1) == 0
