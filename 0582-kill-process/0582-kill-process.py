from collections import defaultdict, deque
from typing import List

class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        tree = defaultdict(list)
        for p, pp in zip(pid, ppid):
            tree[pp].append(p)
        res = []
        q = deque([kill])
        while q:
            cur = q.popleft()
            res.append(cur)
            for child in tree[cur]:
                q.append(child)
        return res
