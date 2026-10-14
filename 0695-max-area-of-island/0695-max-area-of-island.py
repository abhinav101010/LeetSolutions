from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        rows, cols = len(grid), len(grid[0])
        visited = [[False]*cols for _ in range(rows)]
        max_area = 0
        dirs = [(0,1),(1,0),(0,-1),(-1,0)]
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and not visited[r][c]:
                    area = 0
                    stack = [(r,c)]
                    visited[r][c] = True
                    while stack:
                        cr, cc = stack.pop()
                        area += 1
                        for dr, dc in dirs:
                            nr, nc = cr+dr, cc+dc
                            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1 and not visited[nr][nc]:
                                visited[nr][nc] = True
                                stack.append((nr,nc))
                    max_area = max(max_area, area)
        return max_area
