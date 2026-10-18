from typing import List
from collections import defaultdict, deque

class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        tree = defaultdict(list)
        for p, pp in zip(pid, ppid):
            tree[pp].append(p)
        result = []
        queue = deque([kill])
        while queue:
            cur = queue.popleft()
            result.append(cur)
            for child in tree[cur]:
                queue.append(child)
        return result
