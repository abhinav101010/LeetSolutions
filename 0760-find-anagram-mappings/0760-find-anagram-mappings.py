from typing import List
from collections import defaultdict, deque

class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        pos = defaultdict(deque)
        for idx, val in enumerate(B):
            pos[val].append(idx)
        res = []
        for val in A:
            res.append(pos[val].popleft())
        return res
