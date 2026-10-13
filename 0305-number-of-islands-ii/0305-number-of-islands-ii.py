from typing import List

class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        parent = {}
        size = {}
        res = []
        islands = 0
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            nonlocal islands
            rx, ry = find(x), find(y)
            if rx == ry: return 0
            if size[rx] < size[ry]:
                rx, ry = ry, rx
            parent[ry] = rx
            size[rx] += size[ry]
            size.pop(ry)
            islands -= 1
            return -1
        
        for r, c in positions:
            if (r, c) in parent:
                res.append(islands)
                continue
            node = (r, c)
            parent[node] = node
            size[node] = 1
            islands += 1
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if (nr, nc) in parent:
                    union(node, (nr, nc))
            res.append(islands)
        return res