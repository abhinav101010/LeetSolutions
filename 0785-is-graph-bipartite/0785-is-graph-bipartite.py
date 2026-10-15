class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [0] * n  # 0 uncolored, 1 color A, -1 color B
        for start in range(n):
            if color[start] != 0:
                continue
            # BFS
            queue = [start]
            color[start] = 1
            while queue:
                node = queue.pop(0)
                for nb in graph[node]:
                    if color[nb] == 0:
                        color[nb] = -color[node]
                        queue.append(nb)
                    elif color[nb] == color[node]:
                        return False
        return True
