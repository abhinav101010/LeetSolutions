from typing import List
import collections

class Solution:
    def containVirus(self, isInfected: List[List[int]]) -> int:
        n = len(isInfected)
        m = len(isInfected[0])
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        ans = 0
        
        while True:
            # find regions
            visited = [[False]*m for _ in range(n)]
            regions = []  # each region: list of cells, threatened set, walls count
            for i in range(n):
                for j in range(m):
                    if isInfected[i][j] == 1 and not visited[i][j]:
                        # BFS
                        queue = collections.deque()
                        queue.append((i,j))
                        visited[i][j] = True
                        cells = []
                        threatened = set()
                        walls = 0
                        while queue:
                            x,y = queue.popleft()
                            cells.append((x,y))
                            for dx,dy in dirs:
                                nx, ny = x+dx, y+dy
                                if 0 <= nx < n and 0 <= ny < m:
                                    if isInfected[nx][ny] == 1:
                                        if not visited[nx][ny]:
                                            visited[nx][ny] = True
                                            queue.append((nx,ny))
                                    else: # uninfected
                                        threatened.add((nx,ny))
                                        walls += 1
                                else:
                                    # out of bounds, no wall needed? Actually virus can't go out, but we don't build wall outside grid.
                                    pass
                        regions.append({
                            'cells': cells,
                            'threatened': threatened,
                            'walls': walls
                        })
            if not regions:
                break
            
            # find region that threatens most cells
            max_threat = -1
            idx = -1
            for r, reg in enumerate(regions):
                threat = len(reg['threatened'])
                if threat > max_threat:
                    max_threat = threat
                    idx = r
            if max_threat == 0:
                break  # no spread possible
            
            # add walls for selected region
            ans += regions[idx]['walls']
            
            # spread virus from other regions
            for r, reg in enumerate(regions):
                if r == idx:
                    # contain this region: turn its cells to 2 (contained) to prevent further spread
                    for x,y in reg['cells']:
                        isInfected[x][y] = 2
                else:
                    # spread: infect neighboring uninfected cells
                    for x,y in reg['cells']:
                        for dx,dy in dirs:
                            nx, ny = x+dx, y+dy
                            if 0 <= nx < n and 0 <= ny < m and isInfected[nx][ny] == 0:
                                isInfected[nx][ny] = 1
            # after containment, continue loop
        return ans
