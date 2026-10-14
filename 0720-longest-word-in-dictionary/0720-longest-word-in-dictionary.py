from typing import List

class Solution:
    def longestWord(self, words: List[str]) -> str:
        word_set = set(words)
        word_set.add("")
        # sort by length descending, then lexicographically ascending
        words_sorted = sorted(word_set, key=lambda w: (-len(w), w))
        for w in words_sorted:
            ok = True
            for i in range(1, len(w) + 1):
                if w[:i] not in word_set:
                    ok = False
                    break
            if ok:
                return w
        return ""
