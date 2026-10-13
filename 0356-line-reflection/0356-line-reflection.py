from typing import List

class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        if not points:
            return True
        points_set = set((x, y) for x, y in points)
        min_x = min(p[0] for p in points)
        max_x = max(p[0] for p in points)
        sum_x = min_x + max_x
        for x, y in points:
            if (sum_x - x, y) not in points_set:
                return False
        return True