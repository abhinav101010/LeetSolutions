from typing import List
from functools import lru_cache

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        # map from pair to set of possible top chars
        mp = {}
        for a in allowed:
            key = a[:2]
            if key not in mp:
                mp[key] = set()
            mp[key].add(a[2])
        
        @lru_cache(None)
        def dfs(row):
            if len(row) == 1:
                return True
            # compute possible next rows
            options = []
            for i in range(len(row)-1):
                key = row[i:i+2]
                if key not in mp:
                    return False
                options.append(list(mp[key]))
            # generate all combinations
            def backtrack(idx, path):
                if idx == len(options):
                    return dfs(''.join(path))
                for ch in options[idx]:
                    path.append(ch)
                    if backtrack(idx+1, path):
                        return True
                    path.pop()
                return False
            return backtrack(0, [])
        return dfs(bottom)
