class Solution:
    def sumOfNumberAndReverse(self, num) -> bool:
        return any(k + int(str(k)[::-1]) == num for k in range(num + 1))
