from typing import List

class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m, n = len(board), len(board[0])
        r, c = click
        
        if board[r][c] == 'M':
            board[r][c] = 'X'
            return board
        
        def count_mines(r, c):
            count = 0
            for dr in [-1, 0, 1]:
                for dc in [-1, 0, 1]:
                    if dr == 0 and dc == 0:
                        continue
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and board[nr][nc] == 'M':
                        count += 1
            return count
        
        def dfs(r, c):
            if r < 0 or r >= m or c < 0 or c >= n or board[r][c] != 'E':
                return
            mines = count_mines(r, c)
            if mines > 0:
                board[r][c] = str(mines)
            else:
                board[r][c] = 'B'
                for dr in [-1, 0, 1]:
                    for dc in [-1, 0, 1]:
                        if dr == 0 and dc == 0:
                            continue
                        dfs(r + dr, c + dc)
        
        dfs(r, c)
        return board