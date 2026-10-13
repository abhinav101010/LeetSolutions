from collections import deque
from typing import List

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) if grid else 0
        dist = [[0] * n for _ in range(m)]
        reach = [[0] * n for _ in range(m)]
        buildings = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    buildings += 1
                    queue = deque([(i, j, 0)])
                    while queue:
                        x, y, d = queue.popleft()
                        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 0 and reach[nx][ny] == buildings - 1:
                                dist[nx][ny] += d + 1
                                reach[nx][ny] = buildings
                                queue.append((nx, ny, d + 1))
        res = float('inf')
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and reach[i][j] == buildings:
                    res = min(res, dist[i][j])
        return res if res != float('inf') else -1