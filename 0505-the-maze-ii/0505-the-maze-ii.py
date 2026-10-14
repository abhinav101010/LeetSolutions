from typing import List
import heapq

class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        dist = [[float('inf')]*n for _ in range(m)]
        sx, sy = start
        dist[sx][sy] = 0
        heap = [(0, sx, sy)]  # (distance, x, y)
        while heap:
            d, x, y = heapq.heappop(heap)
            if d > dist[x][y]:
                continue
            if x == destination[0] and y == destination[1]:
                return d
            for dx, dy in dirs:
                nx, ny = x, y
                steps = 0
                while 0 <= nx+dx < m and 0 <= ny+dy < n and maze[nx+dx][ny+dy] == 0:
                    nx += dx
                    ny += dy
                    steps += 1
                nd = d + steps
                if nd < dist[nx][ny]:
                    dist[nx][ny] = nd
                    heapq.heappush(heap, (nd, nx, ny))
        return -1
