import heapq

class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        n = len(grid)
        visited = [[False]*n for _ in range(n)]
        heap = [(grid[0][0], 0, 0)]  # (time, r, c)
        visited[0][0] = True
        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        while heap:
            time, r, c = heapq.heappop(heap)
            if r == n-1 and c == n-1:
                return time
            for dr, dc in directions:
                nr, nc = r+dr, c+dc
                if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                    visited[nr][nc] = True
                    nt = max(time, grid[nr][nc])
                    heapq.heappush(heap, (nt, nr, nc))
        return -1
