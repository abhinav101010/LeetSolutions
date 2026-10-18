class Solution:
    def maximizeExpressionOfThree(self, nums):
        a = b = -inf
        c = inf
        for x in nums:
            if x < c:
                c = x
            if x >= a:
                a, b = x, a
            elif x > b:
                b = x
        return a + b - c
