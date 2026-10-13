from typing import List

class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        res = 0
        col_hits = [0] * n
        for i in range(m):
            row_hits = 0
            for j in range(n):
                if grid[i][j] == 'W':
                    row_hits = 0
                    col_hits[j] = 0
                if grid[i][j] == 'E':
                    row_hits += 1
                    col_hits[j] += 1
                if grid[i][j] == '0' or grid[i][j] == 'O':
                    if i == 0 or grid[i - 1][j] == 'W':
                        col_hits[j] = 0
                        for k in range(i, m):
                            if grid[k][j] == 'W':
                                break
                            if grid[k][j] == 'E':
                                col_hits[j] += 1
                    if j == 0 or grid[i][j - 1] == 'W':
                        row_hits = 0
                        for k in range(j, n):
                            if grid[i][k] == 'W':
                                break
                            if grid[i][k] == 'E':
                                row_hits += 1
                    if grid[i][j] == '0':
                        res = max(res, row_hits + col_hits[j])
        return res