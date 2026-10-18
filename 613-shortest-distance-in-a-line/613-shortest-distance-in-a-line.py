class Point:
    def __init__(self, x):
        self.x = x

class Solution:
    def shortestDistance(self, points):
        n = len(points)
        if n < 2:
            return 0
        best = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                d = abs(points[i].x - points[j].x)
                if d < best:
                    best = d
        return 0 if best == float('inf') else best
