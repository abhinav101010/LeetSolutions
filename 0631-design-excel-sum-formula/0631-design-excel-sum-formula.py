from typing import List

class Excel:

    def __init__(self, height: int, width: str):
        """
        :type height: int
        :type width: str
        """
        self.H = height
        self.W = ord(width) - ord('A') + 1
        self.val = [[0] * self.W for _ in range(self.H)]
        # store sum formula as list of (r1,c1,r2,c2) rectangles
        self.formula = [[[] for _ in range(self.W)] for _ in range(self.H)]

    def _parse(self, s: str):
        """
        parse a string like "A1" or "A1:B2" into list of (r1,c1,r2,c2)
        """
        res = []
        if ':' not in s:
            # single cell
            col = ord(s[0]) - ord('A')
            row = int(s[1:]) - 1
            res.append((row, col, row, col))
        else:
            left, right = s.split(':')
            r1c1 = left
            r2c2 = right
            c1 = ord(r1c1[0]) - ord('A')
            r1 = int(r1c1[1:]) - 1
            c2 = ord(r2c2[0]) - ord('A')
            r2 = int(r2c2[1:]) - 1
            # ensure r1 <= r2, c1 <= c2
            if r1 > r2:
                r1, r2 = r2, r1
            if c1 > c2:
                c1, c2 = c2, c1
            res.append((r1, c1, r2, c2))
        return res

    def set(self, row: int, column: str, val: int) -> None:
        """
        :type row: int
        :type column: str
        :type val: int
        :rtype: void
        """
        r = row - 1
        c = ord(column) - ord('A')
        self.val[r][c] = val
        self.formula[r][c].clear()  # clear any sum formula

    def get(self, row: int, column: str) -> int:
        """
        :type row: int
        :type column: str
        :rtype: int
        """
        r = row - 1
        c = ord(column) - ord('A')
        if not self.formula[r][c]:
            return self.val[r][c]
        total = 0
        for (r1, c1, r2, c2) in self.formula[r][c]:
            for i in range(r1, r2 + 1):
                for j in range(c1, c2 + 1):
                    total += self.get(i + 1, chr(ord('A') + j))
        return total

    def sum(self, row: int, column: str, numbers: List[str]) -> int:
        """
        :type row: int
        :type column: str
        :type numbers: List[str]
        :rtype: int
        """
        r = row - 1
        c = ord(column) - ord('A')
        self.formula[r][c] = []
        for num in numbers:
            self.formula[r][c].extend(self._parse(num))
        return self.get(row, column)
