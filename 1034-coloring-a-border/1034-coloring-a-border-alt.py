from collections import deque
class Solution:
    def colorBorder(self, grid, r0, c0, color):
        m, n = len(grid), len(grid[0])
        orig = grid[r0][c0]
        if orig == color:
            return grid
        q = deque([(r0, c0)])
        comp = {(r0, c0)}
        while q:
            r, c = q.popleft()
            for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == orig and (nr, nc) not in comp:
                    comp.add((nr, nc))
                    q.append((nr, nc))
        border = []
        for r, c in comp:
            is_border = (r == 0 or r == m-1 or c == 0 or c == n-1)
            if not is_border:
                for dr, dc in ((1,0),(-1,0),(0,1),(0,-1)):
                    if grid[r+dr][c+dc] != orig:
                        is_border = True
                        break
            if is_border:
                border.append((r, c))
        for r, c in border:
            grid[r][c] = color
        return grid
