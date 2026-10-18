from collections import defaultdict, deque
from typing import List

class Solution:
    def sequenceReconstruction(self, nums: List[int], sequences: List[List[int]]) -> bool:
        n = len(nums)
        graph = defaultdict(list)
        indeg = defaultdict(int)
        for i in range(1, n + 1):
            indeg[i] = 0
        for seq in sequences:
            for a, b in pairwise(seq):
                graph[a].append(b)
                indeg[b] += 1
                indeg[a] -= 1
        q = deque([i for i in range(1, n + 1) if indeg[i] == 0])
        if len(q) != 1:
            return False
        order = []
        while q:
            if len(q) > 1:
                return False
            cur = q.popleft()
            order.append(cur)
            for nxt in graph[cur]:
                indeg[nxt] -= 1
                if indeg[nxt] == 0:
                    q.append(nxt)
        if len(order) != n:
            return False
        return order == nums

# pairwise for older python compatibility if needed
try:
    from itertools import pairwise
except ImportError:
    from itertools import tee
    def pairwise(iterable):
        a, b = tee(iterable)
        next(b, None)
        return zip(a, b)
