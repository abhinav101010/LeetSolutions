from typing import List

class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        n = len(org)
        # index of each value in org
        pos = [0] * (n + 1)
        for i, v in enumerate(org):
            pos[v] = i
        # to check consecutive pairs in org
        # we need that for every consecutive pair (org[i], org[i+1]) appears as consecutive in some seq
        # and that the order is enforced.
        # We'll use indegree and adjacency.
        from collections import defaultdict, deque
        adj = defaultdict(list)
        indeg = [0] * (n + 1)
        nodes_set = set()
        for seq in seqs:
            for v in seq:
                if v < 1 or v > n:
                    return False
                nodes_set.add(v)
            for i in range(len(seq) - 1):
                u, v = seq[i], seq[i+1]
                adj[u].append(v)
                indeg[v] += 1
        # if any node in org not seen in seqs, false
        if nodes_set != set(org):
            return False
        # topological sort with unique order
        q = deque()
        for i in range(1, n+1):
            if indeg[i] == 0:
                q.append(i)
        idx = 0
        while q:
            if len(q) != 1:
                return False  # more than one choice
            u = q.popleft()
            if org[idx] != u:
                return False
            idx += 1
            for v in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)
        return idx == n
