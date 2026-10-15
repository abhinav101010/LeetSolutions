class Solution:
    def shortestPathAllKeys(self, grid: list[str]) -> int:
        m = len(grid)
        n = len(grid[0]) if m else 0
        start = None
        key_count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '@':
                    start = (i, j)
                elif grid[i][j].islower():
                    key_count += 1
        if not start:
            return -1
        from collections import deque
        q = deque()
        visited = set()
        q.append((start[0], start[1], 0, 0))  # row, col, mask, dist
        visited.add((start[0], start[1], 0))
        while q:
            i, j, mask, dist = q.popleft()
            if mask == (1 << key_count) - 1:
                return dist
            for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
                ni, nj = i+di, j+dj
                if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] != '#':
                    ch = grid[ni][nj]
                    nmask = mask
                    if ch.islower():
                        bit = ord(ch) - ord('a')
                        nmask |= (1 << bit)
                    elif ch.isupper():
                        bit = ord(ch) - ord('A')
                        if not (mask & (1 << bit)):
                            continue  # lock without key
                    key = (ni, nj, nmask)
                    if key not in visited:
                        visited.add(key)
                        q.append((ni, nj, nmask, dist+1))
        return -1
