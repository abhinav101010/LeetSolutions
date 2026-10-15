class Solution:
    def numMagicSquaresInside(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0]) if rows else 0
        def magic(r, c):
            # check distinct 1..9
            seen = set()
            for i in range(r, r+3):
                for j in range(c, c+3):
                    val = grid[i][j]
                    if val < 1 or val > 9:
                        return False
                    seen.add(val)
            if len(seen) != 9:
                return False
            # check rows
            target = grid[r][c] + grid[r][c+1] + grid[r][c+2]
            for i in range(r, r+3):
                if grid[i][c] + grid[i][c+1] + grid[i][c+2] != target:
                    return False
            # check cols
            for j in range(c, c+3):
                if grid[r][j] + grid[r+1][j] + grid[r+2][j] != target:
                    return False
            # check diagonals
            if grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != target:
                return False
            if grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != target:
                return False
            return True
        ans = 0
        for r in range(rows-2):
            for c in range(cols-2):
                if magic(r, c):
                    ans += 1
        return ans
