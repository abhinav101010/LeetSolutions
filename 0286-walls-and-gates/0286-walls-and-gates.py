from collections import deque
from typing import List

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms:
            return
        m, n = len(rooms), len(rooms[0])
        queue = deque()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]
        while queue:
            x, y = queue.popleft()
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and rooms[nx][ny] == 2147483647:
                    rooms[nx][ny] = rooms[x][y] + 1
                    queue.append((nx, ny))