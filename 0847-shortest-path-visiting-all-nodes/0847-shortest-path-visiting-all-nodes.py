class Solution:
    def shortestPathLength(self, graph: list[list[int]]) -> int:
        n = len(graph)
        if n == 1:
            return 0
        from collections import deque
        queue = deque()
        visited = set()
        for i in range(n):
            mask = 1 << i
            queue.append((i, mask, 0))
            visited.add((i, mask))
        while queue:
            node, mask, dist = queue.popleft()
            if mask == (1 << n) - 1:
                return dist
            for nei in graph[node]:
                nmask = mask | (1 << nei)
                if (nei, nmask) not in visited:
                    visited.add((nei, nmask))
                    queue.append((nei, nmask, dist + 1))
        return -1
