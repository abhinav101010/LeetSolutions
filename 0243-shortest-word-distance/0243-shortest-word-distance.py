from typing import List

class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        i = j = -1
        res = len(wordsDict)
        for k in range(len(wordsDict)):
            if wordsDict[k] == word1:
                i = k
            if wordsDict[k] == word2:
                j = k
            if i != -1 and j != -1:
                res = min(res, abs(i - j))
        return res