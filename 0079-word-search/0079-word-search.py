class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
# Self thought logic
        firstLetterPos = set()

        # Find first letter
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    firstLetterPos.add((i, j))

        if not firstLetterPos:
            return False

        def findWord(currPos, nextWord, seen, formedWord):
            if not nextWord:
                return formedWord == word

            if currPos in seen:
                return False

            seen.add(currPos)

            r, c = currPos

            # Down
            if (
                r + 1 < len(board)
                and (r + 1, c) not in seen
                and board[r + 1][c] == nextWord[0]
            ):
                if findWord((r + 1, c), nextWord[1:], seen, formedWord + nextWord[0]):
                    seen.remove(currPos)
                    return True

            # Right
            if (
                c + 1 < len(board[0])
                and (r, c + 1) not in seen
                and board[r][c + 1] == nextWord[0]
            ):
                if findWord((r, c + 1), nextWord[1:], seen, formedWord + nextWord[0]):
                    seen.remove(currPos)
                    return True

            # Up
            if (
                r - 1 >= 0
                and (r - 1, c) not in seen
                and board[r - 1][c] == nextWord[0]
            ):
                if findWord((r - 1, c), nextWord[1:], seen, formedWord + nextWord[0]):
                    seen.remove(currPos)
                    return True

            # Left
            if (
                c - 1 >= 0
                and (r, c - 1) not in seen
                and board[r][c - 1] == nextWord[0]
            ):
                if findWord((r, c - 1), nextWord[1:], seen, formedWord + nextWord[0]):
                    seen.remove(currPos)
                    return True

            seen.remove(currPos)
            return False

        for pos in firstLetterPos:
            if findWord(pos, word[1:], set(), word[0]):
                return True

        return False