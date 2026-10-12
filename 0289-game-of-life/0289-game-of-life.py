from typing import List

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        if not board or not board[0]:
            return
        
        m, n = len(board), len(board[0])
        
        # Directions for 8 neighbors
        dirs = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
        
        # First pass: encode new state in higher bits
        # 00 -> 0 (dead stays dead)
        # 01 -> 1 (alive stays alive)
        # 10 -> 2 (dead becomes alive)
        # 11 -> 3 (alive becomes dead)
        
        for i in range(m):
            for j in range(n):
                live = 0
                for di, dj in dirs:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < m and 0 <= nj < n and board[ni][nj] & 1:
                        live += 1
                
                if board[i][j] == 1:
                    if live == 2 or live == 3:
                        board[i][j] = 3  # 11: stays alive
                    else:
                        board[i][j] = 1  # 01: dies
                else:
                    if live == 3:
                        board[i][j] = 2  # 10: becomes alive
                    else:
                        board[i][j] = 0  # 00: stays dead
        
        # Second pass: shift to get new state
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1