class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])
        totalItems = rows * cols

        k %= totalItems
        if k == 0:
            return grid

        flat = []
        for row in grid:
            flat.extend(row)

        newGrid = flat + flat

        startPoint = totalItems - k

        ans = []
        curr = []

        for i in range(startPoint, startPoint + totalItems):
            curr.append(newGrid[i])
            if len(curr) == cols:
                ans.append(curr)
                curr = []

        return ans