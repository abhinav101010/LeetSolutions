from typing import List

class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parent = list(range(n + 1))
        candidate1 = candidate2 = None
        for a, b in edges:
            if parent[b] != b:
                candidate1 = [parent[b], b]
                candidate2 = [a, b]
                continue
            parent[b] = a
        parent = list(range(n + 1))
        for a, b in edges:
            if candidate2 and a == candidate2[0] and b == candidate2[1]:
                continue
            if parent[a] != a:
                parent[a] = find(parent, parent[a])
            else:
                parent[a] = a
            if parent[b] != b:
                parent[b] = find(parent, parent[b])
            else:
                parent[b] = b
            if parent[a] == parent[b]:
                return candidate1 if candidate1 else [a, b]
            parent[parent[b]] = parent[a]
        return candidate2

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]