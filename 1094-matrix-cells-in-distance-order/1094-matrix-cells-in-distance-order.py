class Solution:
    def allCellsDistOrder(self, rows, cols, rCenter, cCenter):
        cells = [(r, c) for r in range(rows) for c in range(cols)]
        cells.sort(key=lambda rc: abs(rc[0]-rCenter) + abs(rc[1]-cCenter))
        return cells
