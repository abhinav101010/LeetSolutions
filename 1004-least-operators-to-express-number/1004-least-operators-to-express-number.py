class Solution:
    def leastOpsExpressTarget(self, x, target):
        pos = 0
        cost = 0
        while target > 0:
            digit = target % x
            target //= x
            if pos == 0:
                cost = digit * 2
            else:
                cost = min(digit * pos + cost, (x - digit) * pos + cost)
            pos += 1
        return cost - 1
