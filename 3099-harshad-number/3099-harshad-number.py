class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        sum = 0
        for c in str(x):
            sum+=int(c)
        return sum if x%sum==0 else -1