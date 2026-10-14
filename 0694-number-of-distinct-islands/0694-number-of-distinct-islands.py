from typing import List

class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        rows, cols = len(grid), len(grid[0])
        visited = [[False]*cols for _ in range(rows)]
        shapes = set()
        dirs = [(0,1),(1,0),(0,-1),(-1,0)]
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and not visited[r][c]:
                    # BFS/DFS to collect cells
                    stack = [(r,c)]
                    visited[r][c] = True
                    cells = []
                    while stack:
                        cr, cc = stack.pop()
                        cells.append((cr, cc))
                        for dr, dc in dirs:
                            nr, nc = cr+dr, cc+dc
                            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1 and not visited[nr][nc]:
                                visited[nr][nc] = True
                                stack.append((nr,nc))
                    # normalize
                    min_r = min(r for r,_ in cells)
                    min_c = min(c for _,c in cells)
                    normalized = sorted((r-min_r, c-min_c) for r,c in cells)
                    shapes.add(tuple(normalized))
        return len(shapes)
