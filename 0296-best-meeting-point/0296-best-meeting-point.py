from typing import List

class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) if grid else 0
        rows, cols = [], []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    rows.append(i)
        for j in range(n):
            for i in range(m):
                if grid[i][j] == 1:
                    cols.append(j)
        res = 0
        for i in range(0, len(rows), 2):
            res += rows[len(rows) - 1 - i] - rows[i]
        for j in range(0, len(cols), 2):
            res += cols[len(cols) - 1 - j] - cols[j]
        return res