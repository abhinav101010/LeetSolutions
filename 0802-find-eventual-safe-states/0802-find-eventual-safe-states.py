class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        n = len(graph)
        # reverse graph
        rgraph = [[] for _ in range(n)]
        outdegree = [0] * n
        for u in range(n):
            for v in graph[u]:
                rgraph[v].append(u)
            outdegree[u] = len(graph[u])
        from collections import deque
        q = deque([i for i in range(n) if outdegree[i] == 0])
        safe = [False] * n
        while q:
            u = q.popleft()
            safe[u] = True
            for v in rgraph[u]:
                outdegree[v] -= 1
                if outdegree[v] == 0:
                    q.append(v)
        return [i for i in range(n) if safe[i]]
