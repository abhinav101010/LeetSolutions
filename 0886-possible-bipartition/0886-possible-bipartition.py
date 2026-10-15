class Solution:
    def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:
        from collections import defaultdict, deque
        graph = defaultdict(list)
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        color = [0] * (n + 1)  # 0 uncolored, 1 and -1 colors
        for start in range(1, n+1):
            if color[start] != 0:
                continue
            # BFS
            q = deque([start])
            color[start] = 1
            while q:
                u = q.popleft()
                for v in graph[u]:
                    if color[v] == 0:
                        color[v] = -color[u]
                        q.append(v)
                    elif color[v] == color[u]:
                        return False
        return True
