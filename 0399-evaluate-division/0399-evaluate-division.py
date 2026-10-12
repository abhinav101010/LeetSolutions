from collections import defaultdict, deque
from typing import List

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)
        for (a, b), val in zip(equations, values):
            graph[a].append((b, val))
            graph[b].append((a, 1.0 / val))
        
        def bfs(start, end):
            if start not in graph or end not in graph:
                return -1.0
            if start == end:
                return 1.0
            
            visited = {start}
            queue = deque([(start, 1.0)])
            
            while queue:
                node, val = queue.popleft()
                if node == end:
                    return val
                for nei, weight in graph[node]:
                    if nei not in visited:
                        visited.add(nei)
                        queue.append((nei, val * weight))
            return -1.0
        
        return [bfs(a, b) for a, b in queries]