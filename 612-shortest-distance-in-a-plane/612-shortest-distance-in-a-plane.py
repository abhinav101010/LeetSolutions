from typing import List


class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


class Solution:
    def shortestDistance(self, points: List[Point]) -> float:
        n = len(points)
        if n < 2:
            return 0.0
        minSq = None
        for i in range(n):
            for j in range(i + 1, n):
                dx = points[i].x - points[j].x
                dy = points[i].y - points[j].y
                sq = dx * dx + dy * dy
                if minSq is None or sq < minSq:
                    minSq = sq
        d = minSq ** 0.5
        return round(d, 2)
