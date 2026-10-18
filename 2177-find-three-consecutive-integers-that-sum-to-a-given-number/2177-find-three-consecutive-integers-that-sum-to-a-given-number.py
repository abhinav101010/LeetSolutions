class Solution:
    def sumOfThree(self, num):
        x, mod = divmod(num, 3)
        return [] if mod else [x - 1, x, x + 1]
