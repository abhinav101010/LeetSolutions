from typing import List

class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        res = []
        s = list(currentState)
        for i in range(len(s) - 1):
            if s[i] == '+' and s[i + 1] == '+':
                s[i] = '-'
                s[i + 1] = '-'
                res.append(''.join(s))
                s[i] = '+'
                s[i + 1] = '+'
        return res