from typing import List
import collections

class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        # count letters in licensePlate
        lp_count = collections.Counter()
        for c in licensePlate.lower():
            if c.isalpha():
                lp_count[c] += 1
        
        best = None
        best_len = float('inf')
        for w in words:
            wc = collections.Counter(w.lower())
            ok = True
            for ch, cnt in lp_count.items():
                if wc[ch] < cnt:
                    ok = False
                    break
            if ok:
                if len(w) < best_len:
                    best_len = len(w)
                    best = w
        return best
