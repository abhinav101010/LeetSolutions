from collections import Counter
from typing import List

class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        count = Counter(s)
        mid = []
        chars = []
        for c, v in count.items():
            if v % 2 == 1:
                mid.append(c)
            chars.extend([c] * (v // 2))
        if len(mid) > 1:
            return []
        res = []
        used = [False] * len(chars)
        
        def backtrack(path):
            if len(path) == len(chars):
                half = ''.join(path)
                res.append(half + ''.join(mid) + half[::-1])
                return
            for i in range(len(chars)):
                if used[i] or (i > 0 and chars[i] == chars[i - 1] and not used[i - 1]):
                    continue
                used[i] = True
                path.append(chars[i])
                backtrack(path)
                path.pop()
                used[i] = False
        
        chars.sort()
        backtrack([])
        return res