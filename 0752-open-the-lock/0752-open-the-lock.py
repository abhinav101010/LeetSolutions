from typing import List
from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0
        dead = set(deadends)
        if "0000" in dead:
            return -1
        q = deque(["0000"])
        visited = {"0000"}
        steps = 0
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if cur == target:
                    return steps
                for nxt in self.neighbors(cur):
                    if nxt not in dead and nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)
            steps += 1
        return -1

    def neighbors(self, s: str):
        res = []
        s_list = list(s)
        for i in range(4):
            orig = s_list[i]
            # turn up
            s_list[i] = '0' if orig == '9' else chr(ord(orig) + 1)
            res.append(''.join(s_list))
            # turn down
            s_list[i] = '9' if orig == '0' else chr(ord(orig) - 1)
            res.append(''.join(s_list))
            # restore
            s_list[i] = orig
        return res
