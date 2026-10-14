from typing import List
from collections import deque

class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m, n = len(maze), len(maze[0])
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        visited = [[False]*n for _ in range(m)]
        q = deque()
        q.append((start[0], start[1]))
        visited[start[0]][start[1]] = True
        while q:
            x, y = q.popleft()
            if x == destination[0] and y == destination[1]:
                return True
            for dx, dy in dirs:
                nx, ny = x, y
                # roll until hit wall
                while 0 <= nx+dx < m and 0 <= ny+dy < n and maze[nx+dx][ny+dy] == 0:
                    nx += dx
                    ny += dy
                # now (nx, ny) is at wall or boundary, the last valid cell is before stepping into wall
                # Actually we stepped one extra? The loop stops when next step is invalid, so (nx,ny) is last valid.
                if not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        return False
