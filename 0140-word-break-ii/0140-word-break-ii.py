from typing import List
from functools import lru_cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        
        @lru_cache(None)
        def dfs(start: int) -> List[str]:
            if start == len(s):
                return [""]
            
            result = []
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in word_set:
                    for suffix in dfs(end):
                        if suffix:
                            result.append(word + " " + suffix)
                        else:
                            result.append(word)
            return result
        
        return dfs(0)