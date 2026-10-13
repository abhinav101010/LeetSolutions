class FenwickTree:
    def __init__(self, m, n):
        self.m = m
        self.n = n
        self.bit = [[0] * (n + 1) for _ in range(m + 1)]
    
    def add(self, i, j, val):
        while i < len(self.bit):
            jj = j
            while jj < len(self.bit[0]):
                self.bit[i][jj] += val
                jj += (jj & -jj)
            i += (i & -i)
    
    def query(self, i, j):
        res = 0
        while i > 0:
            jj = j
            while jj > 0:
                res += self.bit[i][jj]
                jj -= (jj & -jj)
            i -= (i & -i)
        return res

class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if not matrix or not matrix[0]:
            self.m = 0; self.n = 0; self.bit = None; self.matrix = None
            return
        self.m = len(matrix)
        self.n = len(matrix[0])
        self.matrix = [[0] * self.n for _ in range(self.m)]
        self.bit = FenwickTree(self.m, self.n)
        for i in range(self.m):
            for j in range(self.n):
                if matrix[i][j]:
                    self.update(i, j, matrix[i][j])
    
    def update(self, row: int, col: int, val: int) -> None:
        if self.matrix[row][col] == val:
            return
        diff = val - self.matrix[row][col]
        self.matrix[row][col] = val
        self.bit.add(row + 1, col + 1, diff)
    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.bit.query(row2 + 1, col2 + 1) - self.bit.query(row1, col2 + 1) - self.bit.query(row2 + 1, col1) + self.bit.query(row1, col1)