from typing import List

class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        n = len(points)
        if n < 3:
            return False
        cur = 0
        for i in range(n):
            a, b, c = points[i], points[(i + 1) % n], points[(i + 2) % n]
            cross = (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0])
            if cross != 0:
                sign = 1 if cross > 0 else -1
                if cur == 0:
                    cur = sign
                elif cur != sign:
                    return False
        return True
