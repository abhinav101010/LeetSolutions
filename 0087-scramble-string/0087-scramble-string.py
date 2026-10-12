from functools import lru_cache
from typing import List

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        if sorted(s1) != sorted(s2):
            return False
        
        @lru_cache(None)
        def dfs(i1: int, i2: int, length: int) -> bool:
            if s1[i1:i1+length] == s2[i2:i2+length]:
                return True
            if sorted(s1[i1:i1+length]) != sorted(s2[i2:i2+length]):
                return False
            
            for k in range(1, length):
                # No swap
                if dfs(i1, i2, k) and dfs(i1 + k, i2 + k, length - k):
                    return True
                # Swap
                if dfs(i1, i2 + length - k, k) and dfs(i1 + k, i2, length - k):
                    return True
            
            return False
        
        return dfs(0, 0, len(s1))