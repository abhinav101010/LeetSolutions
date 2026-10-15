class Solution:
    def largestIsland(self, grid: list[list[int]]) -> int:
        n = len(grid)
        if n == 0:
            return 0
        # id starts from 2
        id_to_size = {}
        def dfs(r, c, id):
            if r < 0 or r >= n or c < 0 or c >= n or grid[r][c] != 1:
                return 0
            grid[r][c] = id
            size = 1
            size += dfs(r+1, c, id)
            size += dfs(r-1, c, id)
            size += dfs(r, c+1, id)
            size += dfs(r, c-1, id)
            return size
        id = 2
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size = dfs(i, j, id)
                    id_to_size[id] = size
                    id += 1
        # if no zero, whole grid is island
        ans = 0
        for size in id_to_size.values():
            ans = max(ans, size)
        # consider each zero
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()
                    total = 1
                    for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
                        ni, nj = i+dr, j+dc
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                            sid = grid[ni][nj]
                            if sid not in seen:
                                seen.add(sid)
                                total += id_to_size[sid]
                    ans = max(ans, total)
        return ans
