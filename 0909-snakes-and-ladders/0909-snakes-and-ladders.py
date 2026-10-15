class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        n = len(board)
        # label to (r,c) mapping: boustrophedon
        def get_coord(s):
            # s from 1 to n*n
            quot, rem = divmod(s-1, n)
            r = n - 1 - quot
            c = rem if (n-1-quot) % 2 == 0 else n - 1 - rem
            return r, c
        from collections import deque
        visited = [False] * (n*n + 1)
        q = deque()
        q.append((1, 0))  # position, steps
        visited[1] = True
        while q:
            s, steps = q.popleft()
            if s == n*n:
                return steps
            for nxt in range(s+1, min(s+6, n*n)+1):
                r, c = get_coord(nxt)
                if board[r][c] != -1:
                    nxt = board[r][c]
                if not visited[nxt]:
                    visited[nxt] = True
                    q.append((nxt, steps+1))
        return -1
