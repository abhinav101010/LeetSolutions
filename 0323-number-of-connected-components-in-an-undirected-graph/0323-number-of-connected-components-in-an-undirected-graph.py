from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n))
        size = [1] * n
        count = n
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            nonlocal count
            rx, ry = find(x), find(y)
            if rx == ry: return
            if size[rx] < size[ry]:
                rx, ry = ry, rx
            parent[ry] = rx
            size[rx] += size[ry]
            size[ry] = 0
            count -= 1
        
        for a, b in edges:
            union(a, b)
        return count