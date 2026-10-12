class Solution:
    def solve(self, board: List[List[str]]) -> None:
# Self thought working approch but gives TLE
        # rows, cols = len(board), len(board[0])

        # def recurr(i, j, visited):
        #     if board[i][j] == "X":
        #         return False

        #     if (i, j) in visited:
        #         return False

        #     if i == 0 or j == 0 or i == rows - 1 or j == cols - 1:
        #         return True

        #     visited.add((i, j))

        #     reachesBorder = (
        #         recurr(i + 1, j, visited) or
        #         recurr(i - 1, j, visited) or
        #         recurr(i, j + 1, visited) or
        #         recurr(i, j - 1, visited)
        #     )

        #     visited.remove((i, j))
        #     return reachesBorder

        # if rows == 1 or cols == 1: return 

        # for i in range(1, rows - 1):
        #     for j in range(1, cols - 1):
        #         if board[i][j] == "O":
        #             if not recurr(i, j, set()):
        #                 board[i][j] = "X"


# Another thought logic
        rows, cols = len(board), len(board[0])

        def dfs(i, j):
            if (
                i < 0 or i >= rows or
                j < 0 or j >= cols or
                board[i][j] != "O"
            ):
                return

            board[i][j] = "#"

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        # check border
        for i in range(rows):
            dfs(i, 0)
            dfs(i, cols - 1)

        for j in range(cols):
            dfs(0, j)
            dfs(rows - 1, j)

        # switch
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == "O":
                    board[i][j] = "X"
                elif board[i][j] == "#":
                    board[i][j] = "O"