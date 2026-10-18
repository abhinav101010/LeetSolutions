class Solution:
    def hitBricks(self, grid: list[list[int]], hits: list[list[int]]) -> list[int]:
        m, n = len(grid), len(grid[0])
        total = m * n
        parent = list(range(total + 1))
        size = [1] * (total + 1)

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(a, b):
            a, b = find(a), find(b)
            if a == b:
                return
            if size[a] < size[b]:
                a, b = b, a
            parent[b] = a
            size[a] += size[b]

        def idx(r, c):
            return r * n + c

        g = [row[:] for row in grid]
        for r, c in hits:
            g[r][c] = 0

        for c in range(n):
            if g[0][c] == 1:
                union(idx(0, c), total)
        for r in range(1, m):
            for c in range(n):
                if g[r][c] == 1:
                    if g[r-1][c] == 1:
                        union(idx(r, c), idx(r-1, c))
                    if c > 0 and g[r][c-1] == 1:
                        union(idx(r, c), idx(r, c-1))

        res = [0] * len(hits)
        prev = size[find(total)]
        for i in range(len(hits) - 1, -1, -1):
            r, c = hits[i]
            if grid[r][c] == 0:
                res[i] = 0
                continue
            g[r][c] = 1
            if r == 0:
                union(idx(r, c), total)
            if r > 0 and g[r-1][c] == 1:
                union(idx(r, c), idx(r-1, c))
            if r < m - 1 and g[r+1][c] == 1:
                union(idx(r, c), idx(r+1, c))
            if c > 0 and g[r][c-1] == 1:
                union(idx(r, c), idx(r, c-1))
            if c < n - 1 and g[r][c+1] == 1:
                union(idx(r, c), idx(r, c+1))
            curr = size[find(total)]
            res[i] = max(0, curr - prev - 1)
            prev = curr
        return res