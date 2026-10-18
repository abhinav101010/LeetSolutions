class Solution:
    def isBoomerang(self, points):
        (x1, y1), (x2, y2), (x3, y3) = points
        # distinct and not collinear
        return (x1 != x2 or y1 != y2) and (x1 != x3 or y1 != y3) and (x2 != x3 or y2 != y3) and \
               (x2 - x1) * (y3 - y1) != (x3 - x1) * (y2 - y1)
