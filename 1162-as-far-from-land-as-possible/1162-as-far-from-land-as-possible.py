class Solution:
    def maxDistance(self, grid) -> int:
        n = len(grid)
        from collections import deque
        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j))
        if not q or len(q) == n * n:
            return -1
        ans = -1
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        while q:
            ans += 1
            for _ in range(len(q)):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                        grid[nr][nc] = 1
                        q.append((nr, nc))
        return ans
