class Solution:
    def removeZeros(self, n):
        k = 1
        ans = 0
        while n:
            x = n % 10
            if x:
                ans = k * x + ans
                k *= 10
            n //= 10
        return ans
