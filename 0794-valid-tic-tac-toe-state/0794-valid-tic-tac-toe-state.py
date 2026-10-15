class Solution:
    def validTicTacToeState(self, board: list[str]) -> bool:
        # Count X and O
        x_count = sum(row.count('X') for row in board)
        o_count = sum(row.count('O') for row in board)
        # Counts must be equal or x one more
        if not (x_count == o_count or x_count == o_count + 1):
            return False
        # Helper to check if player wins
        def win(player):
            # rows
            for r in range(3):
                if all(board[r][c] == player for c in range(3)):
                    return True
            # cols
            for c in range(3):
                if all(board[r][c] == player for r in range(3)):
                    return True
            # diagonals
            if all(board[i][i] == player for i in range(3)):
                return True
            if all(board[i][2 - i] == player for i in range(3)):
                return True
            return False
        x_win = win('X')
        o_win = win('O')
        # Both cannot win
        if x_win and o_win:
            return False
        # If X wins, X count must be one more than O
        if x_win and x_count != o_count + 1:
            return False
        # If O wins, counts must be equal
        if o_win and x_count != o_count:
            return False
        return True
