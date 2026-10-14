from typing import List

class Solution:
    def candyCrush(self, board: List[List[int]]) -> List[List[int]]:
        m = len(board)
        n = len(board[0])
        while True:
            crush = False
            # mark horizontal crushes
            for i in range(m):
                for j in range(n - 2):
                    v = abs(board[i][j])
                    if v != 0 and abs(board[i][j+1]) == v and abs(board[i][j+2]) == v:
                        board[i][j] = board[i][j+1] = board[i][j+2] = -v
                        crush = True
            # mark vertical crushes
            for i in range(m - 2):
                for j in range(n):
                    v = abs(board[i][j])
                    if v != 0 and abs(board[i+1][j]) == v and abs(board[i+2][j]) == v:
                        board[i][j] = board[i+1][j] = board[i+2][j] = -v
                        crush = True
            if not crush:
                break
            # set marked to zero
            for i in range(m):
                for j in range(n):
                    if board[i][j] < 0:
                        board[i][j] = 0
            # drop columns
            for j in range(n):
                write_idx = m - 1
                for i in range(m - 1, -1, -1):
                    if board[i][j] != 0:
                        board[write_idx][j] = board[i][j]
                        write_idx -= 1
                for i in range(write_idx, -1, -1):
                    board[i][j] = 0
        return board
