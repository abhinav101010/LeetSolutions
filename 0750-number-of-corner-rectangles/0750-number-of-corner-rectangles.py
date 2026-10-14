from typing import List

class Solution:
    def numberOfCornerRectangles(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        ans = 0
        for c1 in range(C):
            for c2 in range(c1+1, C):
                cnt = 0
                for r in range(R):
                    if grid[r][c1] == 1 and grid[r][c2] == 1:
                        cnt += 1
                ans += cnt * (cnt - 1) // 2
        return ans
