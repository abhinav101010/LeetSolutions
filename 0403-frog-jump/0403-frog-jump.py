from typing import List

class Solution:
    def canCross(self, stones: List[int]) -> bool:
        stone_set = set(stones)
        memo = {}
        
        def dfs(pos: int, k: int) -> bool:
            if pos == stones[-1]:
                return True
            if (pos, k) in memo:
                return memo[(pos, k)]
            
            for step in (k - 1, k, k + 1):
                if step > 0 and pos + step in stone_set:
                    if dfs(pos + step, step):
                        memo[(pos, k)] = True
                        return True
            
            memo[(pos, k)] = False
            return False
        
        return dfs(0, 0)