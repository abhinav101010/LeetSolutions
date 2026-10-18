class Solution:
    def generateKey(self, num1, num2, num3):
        ans, k = 0, 1
        for _ in range(4):
            x = min(num1 // k % 10, num2 // k % 10, num3 // k % 10)
            ans += x * k
            k *= 10
        return ans
