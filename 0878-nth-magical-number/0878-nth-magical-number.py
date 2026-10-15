import math

class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        MOD = 10**9 + 7
        def lcm(x, y):
            return x // math.gcd(x, y) * y
        l = lcm(a, b)
        lo, hi = min(a, b), n * min(a, b)
        while lo < hi:
            mid = (lo + hi) // 2
            count = mid // a + mid // b - mid // l
            if count < n:
                lo = mid + 1
            else:
                hi = mid
        return lo % MOD
