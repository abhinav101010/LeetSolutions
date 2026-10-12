from collections import deque
from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
        
        m, n = len(heights), len(heights[0])
        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        
        def bfs(queue, visited):
            while queue:
                x, y = queue.popleft()
                for dx, dy in [(0,1), (0,-1), (1,0), (-1,0)]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and heights[nx][ny] >= heights[x][y]:
                        visited[nx][ny] = True
                        queue.append((nx, ny))
        
        pacific_q = deque()
        atlantic_q = deque()
        
        for i in range(m):
            pacific[i][0] = True
            pacific_q.append((i, 0))
            atlantic[i][n-1] = True
            atlantic_q.append((i, n-1))
        
        for j in range(n):
            pacific[0][j] = True
            pacific_q.append((0, j))
            atlantic[m-1][j] = True
            atlantic_q.append((m-1, j))
        
        bfs(pacific_q, pacific)
        bfs(atlantic_q, atlantic)
        
        result = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        return result