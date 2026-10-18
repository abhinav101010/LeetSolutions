class Solution:
    def smallestFactorization(self, a: int) -> int:
        if a < 2:
            return a
        res = []
        for d in range(9, 1, -1):
            while a % d == 0:
                a //= d
                res.append(d)
        if a > 1:
            return 0
        # construct number from digits in reverse order (since we collected from largest to smallest)
        num = 0
        for d in reversed(res):
            num = num * 10 + d
            if num > 2**31 - 1:
                return 0
        return num
