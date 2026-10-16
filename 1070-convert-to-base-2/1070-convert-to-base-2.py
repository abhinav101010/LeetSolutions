class Solution:
    def baseNeg2(self, n):
        if n == 0:
            return "0"
        res = []
        while n:
            r = n % 2
            n = -(n // 2)
            res.append(str(r))
        return ''.join(reversed(res))
