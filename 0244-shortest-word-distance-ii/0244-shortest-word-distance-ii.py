from collections import defaultdict
from typing import List

class WordDistance:
    def __init__(self, wordsDict: List[str]):
        self.pos = defaultdict(list)
        for i, w in enumerate(wordsDict):
            self.pos[w].append(i)
    
    def shortest(self, word1: str, word2: str) -> int:
        p1, p2 = self.pos[word1], self.pos[word2]
        i = j = 0
        res = float('inf')
        while i < len(p1) and j < len(p2):
            res = min(res, abs(p1[i] - p2[j]))
            if p1[i] < p2[j]:
                i += 1
            else:
                j += 1
        return res