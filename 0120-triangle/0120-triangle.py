class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        memo = {}
        def recurr(row, i):
            if row == len(triangle):
                return 0
            if (row, i) in memo:
                return memo[(row, i)]

            memo[(row, i)] = triangle[row][i] + min(
                recurr(row + 1, i),
                recurr(row + 1, i + 1)
            )

            return memo[(row, i)]
        return recurr(0, 0)