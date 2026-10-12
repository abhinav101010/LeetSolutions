class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            seenRow = []
            seenCol = []
            for j in range(len(board)):
                if board[i][j] != ".":
                    if board[i][j] in seenRow: return False
                    seenRow.append(board[i][j])

                if board[j][i] != ".":
                    if board[j][i] in seenCol: return False
                    seenCol.append(board[j][i])
            seenRow.clear()
            seenCol.clear()

        for boxRow in range(0,9,3):
            for boxCol in range(0,9,3):
                seen = set()
                for i in range(boxRow, boxRow + 3):
                    for j in range(boxCol, boxCol + 3):
                        if board[i][j] == ".":
                            continue
                        if board[i][j] in seen:
                            return False
                        seen.add(board[i][j])
        
        return True
