from collections import deque
class Solution:
    def minimumSemesters(self, n, relations):
        adj = [[] for _ in range(n)]
        indeg = [0] * n
        for u, v in relations:
            adj[u - 1].append(v - 1)
            indeg[v - 1] += 1
        q = deque(i for i in range(n) if indeg[i] == 0)
        sem = 0
        taken = 0
        while q:
            sem += 1
            for _ in range(len(q)):
                u = q.popleft()
                taken += 1
                for v in adj[u]:
                    indeg[v] -= 1
                    if indeg[v] == 0:
                        q.append(v)
        return sem if taken == n else -1
