from typing import List

class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        res = len(wordsDict)
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                for j in range(len(wordsDict)):
                    if wordsDict[j] == word2 and i != j:
                        res = min(res, abs(i - j))
        return res