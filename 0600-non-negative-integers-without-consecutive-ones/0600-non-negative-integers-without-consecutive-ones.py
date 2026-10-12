from functools import lru_cache

class Solution:
    def findIntegers(self, n: int) -> int:
        @lru_cache(None)
        def dp(i, prev, tight):
            if i == len(bits):
                return 1
            limit = bits[i] if tight else 1
            total = 0
            for d in range(limit + 1):
                if prev == 1 and d == 1:
                    continue
                total += dp(i + 1, d, tight and d == limit)
            return total
        
        bits = []
        while n:
            bits.append(n & 1)
            n >>= 1
        bits = bits[::-1]
        
        return dp(0, 0, True)