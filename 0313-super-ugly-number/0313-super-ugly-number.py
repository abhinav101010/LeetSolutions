import heapq
from typing import List

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly = [1]
        idx = [0] * len(primes)
        val = list(primes)
        
        for _ in range(1, n):
            next_ugly = min(val)
            ugly.append(next_ugly)
            
            for i in range(len(primes)):
                if val[i] == next_ugly:
                    idx[i] += 1
                    val[i] = ugly[idx[i]] * primes[i]
        
        return ugly[-1]