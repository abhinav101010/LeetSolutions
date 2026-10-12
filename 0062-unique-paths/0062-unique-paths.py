class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memory = {}
        def path(col, row):
            if col == m and row == n:
                return 1

            if (col, row) in memory:
                return memory[(col, row)]
            ways=0
            if col < m:
                ways+=path(col+1, row)

            if row < n:
                ways+=path(col, row+1)

            memory[(col, row)] = ways
            return ways

        return path(1,1)