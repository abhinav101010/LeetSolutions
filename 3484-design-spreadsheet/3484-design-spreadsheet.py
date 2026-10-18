class Spreadsheet:
    def __init__(self, rows):
        self.d = {}

    def setCell(self, cell, value):
        self.d[cell] = value

    def resetCell(self, cell):
        self.d.pop(cell, None)

    def getValue(self, formula):
        ans = 0
        for cell in formula[1:].split("+"):
            ans += int(cell) if cell[0].isdigit() else self.d.get(cell, 0)
        return ans


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
