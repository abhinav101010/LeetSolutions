import heapq
from collections import Counter

class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        if k <= 1:
            return s
        count = Counter(s)
        max_heap = [(-freq, char) for char, freq in count.items()]
        heapq.heapify(max_heap)
        queue = []
        res = []
        while max_heap:
            freq, char = heapq.heappop(max_heap)
            res.append(char)
            queue.append((freq + 1, char))
            if len(queue) == k:
                nf, nc = queue.pop(0)
                if nf < 0:
                    heapq.heappush(max_heap, (nf, nc))
        return ''.join(res) if len(res) == len(s) else ""