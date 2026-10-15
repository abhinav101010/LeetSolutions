class Solution:
    def matrixScore(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # ensure first column is 1 by flipping rows
        for i in range(m):
            if grid[i][0] == 0:
                for j in range(n):
                    grid[i][j] ^= 1
        ans = 0
        for j in range(n):
            cnt = sum(grid[i][j] for i in range(m))
            cnt = max(cnt, m - cnt)
            ans += cnt * (1 << (n - 1 - j))
        return ans
