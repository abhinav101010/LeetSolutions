from typing import List
import heapq

class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m, n = len(maze), len(maze[0])
        dirs = [(-1,0,'u'),(1,0,'d'),(0,-1,'l'),(0,1,'r')]
        # distance and path for each cell
        dist = [[float('inf')]*n for _ in range(m)]
        path = [['']*n for _ in range(m)]
        sx, sy = ball
        hx, hy = hole
        dist[sx][sy] = 0
        path[sx][sy] = ''
        heap = [(0, '', sx, sy)]  # (distance, path, x, y)
        while heap:
            d, p, x, y = heapq.heappop(heap)
            if d > dist[x][y] or (d == dist[x][y] and p > path[x][y]):
                continue
            if x == hx and y == hy:
                return p
            for dx, dy, ch in dirs:
                nx, ny = x, y
                steps = 0
                # roll
                while 0 <= nx+dx < m and 0 <= ny+dy < n and maze[nx+dx][ny+dy] == 0:
                    nx += dx
                    ny += dy
                    steps += 1
                    if nx == hx and ny == hy:
                        # we can stop at hole mid-roll
                        break
                # after rolling, we are at (nx, ny) which is either at wall or hole (if we broke)
                nd = d + steps
                np = p + ch
                if nd < dist[nx][ny] or (nd == dist[nx][ny] and np < path[nx][ny]):
                    dist[nx][ny] = nd
                    path[nx][ny] = np
                    heapq.heappush(heap, (nd, np, nx, ny))
        return "impossible"
