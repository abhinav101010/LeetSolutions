class Solution:
    def numEnclaves(self, grid):
        m, n = len(grid), len(grid[0])
        def dfs(x, y):
            if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                grid[x][y] = 0
                for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
                    dfs(x+dx, y+dy)
        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m-1 or j == 0 or j == n-1) and grid[i][j] == 1:
                    dfs(i, j)
        return sum(cell == 1 for row in grid for cell in row)
