class Solution:
    def shortestBridge(self, A: list[list[int]]) -> int:
        n = len(A)
        from collections import deque
        q = deque()
        # find first island and mark it as 2
        found = False
        def dfs(r, c):
            if r < 0 or r >= n or c < 0 or c >= n or A[r][c] != 1:
                return
            A[r][c] = 2
            q.append((r, c))
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
        for i in range(n):
            if found: break
            for j in range(n):
                if A[i][j] == 1:
                    dfs(i, j)
                    found = True
                    break
        # BFS
        steps = 0
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                for dr, dc in dirs:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < n and 0 <= nc < n:
                        if A[nr][nc] == 1:
                            return steps
                        if A[nr][nc] == 0:
                            A[nr][nc] = 2  # mark visited
                            q.append((nr, nc))
            steps += 1
        return -1
