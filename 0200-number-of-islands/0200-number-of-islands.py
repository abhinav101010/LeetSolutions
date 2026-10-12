class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
# Self thought Logic and implemented
        rows = len(grid)
        cols = len(grid[0])

        seen = set()

        def joinCompleteIsle(i, j):
            if i < 0 or i >= rows or j < 0 or j >= cols:
                return

            if grid[i][j] == "0":
                return

            if (i, j) in seen:
                return

            seen.add((i, j))

            joinCompleteIsle(i + 1, j)
            joinCompleteIsle(i - 1, j)
            joinCompleteIsle(i, j + 1)
            joinCompleteIsle(i, j - 1)

        ans = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1" and (i, j) not in seen:
                    ans += 1
                    joinCompleteIsle(i, j)

        return ans