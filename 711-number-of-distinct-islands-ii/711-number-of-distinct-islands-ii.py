from typing import List

class Solution:
    def numDistinctIslands2(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        visited = [[False]*n for _ in range(m)]
        def dfs(x, y, cells):
            if x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or grid[x][y] == 0:
                return
            visited[x][y] = True
            cells.append((x, y))
            dfs(x+1, y, cells)
            dfs(x-1, y, cells)
            dfs(x, y+1, cells)
            dfs(x, y-1, cells)
        def transform(points, rot, reflect):
            # rot: 0,1,2,3 times 90 degrees clockwise
            # reflect: whether to reflect over y-axis (i.e., multiply x by -1) after rotation?
            res = []
            for (x, y) in points:
                xr, yr = x, y
                for _ in range(rot):
                    xr, yr = yr, -xr
                if reflect:
                    xr = -xr
                res.append((xr, yr))
            return res
        def normalize(shape):
            # shape: list of (x,y)
            minx = min(p[0] for p in shape)
            miny = min(p[1] for p in shape)
            normalized = sorted((p[0]-minx, p[1]-miny) for p in shape)
            return tuple(normalized)
        signatures = set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visited[i][j]:
                    cells = []
                    dfs(i, j, cells)
                    # generate 8 transformations
                    cand = None
                    for rot in range(4):
                        for ref in [False, True]:
                            t = transform(cells, rot, ref)
                            norm = normalize(t)
                            if cand is None or norm < cand:
                                cand = norm
                    signatures.add(cand)
        return len(signatures)
