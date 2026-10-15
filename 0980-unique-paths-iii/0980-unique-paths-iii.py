class Solution:
    def uniquePathsIII(self, grid):
        m, n = len(grid), len(grid[0])
        start = None
        zero_count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    start = (i, j)
                elif grid[i][j] == 0:
                    zero_count += 1
        def dfs(x, y, remaining):
            if not (0 <= x < m and 0 <= y < n) or grid[x][y] == -1:
                return 0
            if grid[x][y] == 2:
                return 1 if remaining == 0 else 0
            tmp = grid[x][y]
            grid[x][y] = -1  # mark visited
            paths = 0
            for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                paths += dfs(x+dx, y+dy, remaining-1)
            grid[x][y] = tmp
            return paths
        return dfs(start[0], start[1], zero_count)
