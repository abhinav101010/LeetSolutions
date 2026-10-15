class Solution:
    def minAreaRect(self, points: list[list[int]]) -> int:
        point_set = set()
        for x, y in points:
            point_set.add((x, y))
        ans = float('inf')
        n = len(points)
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                if x1 == x2 or y1 == y2:
                    continue
                if (x1, y2) in point_set and (x2, y1) in point_set:
                    area = abs(x1 - x2) * abs(y1 - y2)
                    if area < ans:
                        ans = area
        return 0 if ans == float('inf') else ans
