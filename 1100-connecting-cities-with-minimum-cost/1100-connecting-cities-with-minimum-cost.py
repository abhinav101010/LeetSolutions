class Solution:
    def minimumCost(self, N, connections):
        connections.sort(key=lambda x: x[2])
        parent = list(range(N + 1))
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry: return False
            parent[rx] = ry
            return True
        cost = 0
        edges = 0
        for x, y, c in connections:
            if union(x, y):
                cost += c
                edges += 1
        return cost if edges == N - 1 else -1
