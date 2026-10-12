class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        # Find rook
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    r, c = i, j

        ans = 0

        # Up
        for i in range(r - 1, -1, -1):
            if board[i][c] != '.':
                if board[i][c] == 'p':
                    ans += 1
                break

        # Down
        for i in range(r + 1, 8):
            if board[i][c] != '.':
                if board[i][c] == 'p':
                    ans += 1
                break

        # Left
        for j in range(c - 1, -1, -1):
            if board[r][j] != '.':
                if board[r][j] == 'p':
                    ans += 1
                break

        # Right
        for j in range(c + 1, 8):
            if board[r][j] != '.':
                if board[r][j] == 'p':
                    ans += 1
                break

        return ans