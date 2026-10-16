class Solution:
    def smallestRepunitDivByK(self, k):
        if k % 2 == 0 or k % 5 == 0: return -1
        remainder = 0
        length = 1
        while remainder != 0 or length == 1:
            remainder = (remainder * 10 + 1) % k
            if remainder == 0:
                return length
            length += 1
        return -1
