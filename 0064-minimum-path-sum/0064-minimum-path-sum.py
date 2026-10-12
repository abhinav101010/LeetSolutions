class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # ans = float("inf")

        # def move(curr, total):
        #     nonlocal ans

        #     rows = len(grid)
        #     cols = len(grid[0])

        #     if curr == [rows - 1, cols - 1]:
        #         ans = min(ans, total)
        #         return

        #     # Move right
        #     if curr[1] + 1 < cols:
        #         move(
        #             [curr[0], curr[1] + 1],
        #             total + grid[curr[0]][curr[1] + 1]
        #         )

        #     # Move down
        #     if curr[0] + 1 < rows:
        #         move(
        #             [curr[0] + 1, curr[1]],
        #             total + grid[curr[0] + 1][curr[1]]
        #         )

        # move([0, 0], grid[0][0])
        # return ans

        rows = len(grid)
        cols = len(grid[0])

        memo = {}

        def dfs(r, c):
            if r == rows - 1 and c == cols - 1:
                return grid[r][c]

            if r >= rows or c >= cols:
                return float("inf")

            if (r, c) in memo:
                return memo[(r, c)]

            memo[(r, c)] = grid[r][c] + min(
                dfs(r + 1, c),
                dfs(r, c + 1)
            )

            return memo[(r, c)]

        return dfs(0, 0)