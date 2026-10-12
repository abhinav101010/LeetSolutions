class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [[""] * 3 for _ in range(3)]

        for i, (r, c) in enumerate(moves):
            board[r][c] = "X" if i % 2 == 0 else "O"

        lines = []

        # Rows
        lines += board

        # Columns
        for c in range(3):
            lines.append([board[0][c], board[1][c], board[2][c]])

        # Diagonals
        lines.append([board[0][0], board[1][1], board[2][2]])
        lines.append([board[0][2], board[1][1], board[2][0]])

        for line in lines:
            if line == ["X", "X", "X"]:
                return "A"
            if line == ["O", "O", "O"]:
                return "B"

        if len(moves) == 9:
            return "Draw"

        return "Pending"