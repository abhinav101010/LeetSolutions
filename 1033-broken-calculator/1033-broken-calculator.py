class Solution:
    def brokenCalc(self, x, y):
        if x >= y: return x - y
        ans = 0
        while y > x:
            if y % 2 == 1:
                y += 1
            else:
                y //= 2
            ans += 1
        return ans + x - y
