from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        # sort by (-freq, word)
        sorted_items = sorted(cnt.items(), key=lambda x: (-x[1], x[0]))
        return [word for word, _ in sorted_items[:k]]
