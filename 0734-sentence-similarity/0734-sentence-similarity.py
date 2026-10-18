from typing import List

class Solution:
    def areSentencesSimilar(self, words1: List[str], words2: List[str], pairs: List[List[str]]) -> bool:
        if len(words1) != len(words2):
            return False
        similar = set()
        for a, b in pairs:
            similar.add((a, b))
            similar.add((b, a))
        for w1, w2 in zip(words1, words2):
            if w1 == w2:
                continue
            if (w1, w2) not in similar:
                return False
        return True
