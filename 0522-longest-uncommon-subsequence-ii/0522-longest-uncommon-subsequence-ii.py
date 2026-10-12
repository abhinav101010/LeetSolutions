from typing import List
from collections import Counter

class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        count = Counter(strs)
        unique_strs = sorted(set(strs), key=len, reverse=True)
        
        def is_subsequence(s, t):
            if len(s) > len(t):
                return False
            i = 0
            for ch in t:
                if i < len(s) and s[i] == ch:
                    i += 1
            return i == len(s)
        
        for s in unique_strs:
            if count[s] == 1:
                if all(not is_subsequence(s, t) for t in unique_strs if t != s):
                    return len(s)
        return -1