import math

class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)
        max_m = int(math.log2(num)) + 1
        
        for m in range(max_m, 1, -1):
            k = int(num ** (1.0 / m))
            if k <= 1:
                continue
            total = (k ** (m + 1) - 1) // (k - 1)
            if total == num:
                return str(k)
        
        return str(num - 1)