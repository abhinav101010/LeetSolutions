import heapq
from typing import List

class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        m, n = len(forest), len(forest[0])
        trees = []
        for i in range(m):
            for j in range(n):
                if forest[i][j] > 1:
                    trees.append((forest[i][j], i, j))
        trees.sort()
        
        def bfs(sx, sy, tx, ty):
            if sx == tx and sy == ty:
                return 0
            queue = deque([(sx, sy, 0)])
            visited = set([(sx, sy)])
            dirs = [(-1,0),(1,0),(0,-1),(0,1)]
            while queue:
                x, y, dist = queue.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and forest[nx][ny] != 0 and (nx, ny) not in visited:
                        if nx == tx and ny == ty:
                            return dist + 1
                        visited.add((nx, ny))
                        queue.append((nx, ny, dist + 1))
            return -1
        
        ans = 0
        sx, sy = 0, 0
        for _, tx, ty in trees:
            d = bfs(sx, sy, tx, ty)
            if d == -1:
                return -1
            ans += d
            sx, sy = tx, ty
        return ans