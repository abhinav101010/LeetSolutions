import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        cnt = Counter(s)
        max_heap = [(-freq, ch) for ch, freq in cnt.items()]
        heapq.heapify(max_heap)
        prev_char = None
        prev_freq = 0
        res = []
        while max_heap:
            freq, ch = heapq.heappop(max_heap)
            res.append(ch)
            if prev_char is not None and prev_freq < 0:
                heapq.heappush(max_heap, (prev_freq, prev_char))
            prev_char = ch
            prev_freq = freq + 1  # because freq is negative, adding 1 increases (less negative)
        res_str = ''.join(res)
        if len(res_str) != len(s):
            return ""
        return res_str
