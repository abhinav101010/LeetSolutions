from typing import List

class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        if not picture or not picture[0]:
            return 0
        m, n = len(picture), len(picture[0])
        rows = [0] * m
        cols = [0] * n
        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B':
                    rows[i] += 1
                    cols[j] += 1
        lonely = 0
        for i in range(m):
            for j in range(n):
                if picture[i][j] == 'B' and rows[i] == 1 and cols[j] == 1:
                    lonely += 1
        return lonely
