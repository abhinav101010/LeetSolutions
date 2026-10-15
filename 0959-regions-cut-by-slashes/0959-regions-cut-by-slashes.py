class Solution:
    def regionsBySlashes(self, grid: list[str]) -> int:
        n = len(grid)
        # expand to 3n x 3n
        N = n * 3
        g = [[0]*N for _ in range(N)]
        for r in range(n):
            row = grid[r]
            for c in range(n):
                if row[c] == '/':
                    g[r*3][c*3+2] = 1
                    g[r*3+1][c*3+1] = 1
                    g[r*3+2][c*3] = 1
                elif row[c] == '\\':
                    g[r*3][c*3] = 1
                    g[r*3+1][c*3+1] = 1
                    g[r*3+2][c*3+2] = 1
                # else space: leave zeros
        # count connected components of zeros
        def dfs(x, y):
            if x < 0 or x >= N or y < 0 or y >= N or g[x][y] != 0:
                return
            g[x][y] = 1
            dfs(x+1, y)
            dfs(x-1, y)
            dfs(x, y+1)
            dfs(x, y-1)
        ans = 0
        for i in range(N):
            for j in range(N):
                if g[i][j] == 0:
                    ans += 1
                    dfs(i, j)
        return ans
