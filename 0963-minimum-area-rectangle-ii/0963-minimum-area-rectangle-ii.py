class Solution:
    def minAreaFreeRect(self, points: list[list[int]]) -> float:
        n = len(points)
        from collections import defaultdict
        mp = defaultdict(list)  # key -> list of (dx, dy)
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                mx = x1 + x2
                my = y1 + y2
                dx = x1 - x2
                dy = y1 - y2
                dist2 = dx*dx + dy*dy
                mp[(mx, my, dist2)].append((dx, dy))
        ans = float('inf')
        for vecs in mp.values():
            m = len(vecs)
            if m < 2:
                continue
            for i in range(m):
                x1, y1 = vecs[i]
                for j in range(i+1, m):
                    x2, y2 = vecs[j]
                    area = abs(x1*y2 - y1*x2) / 2.0
                    if area > 0 and area < ans:
                        ans = area
        return 0 if ans == float('inf') else ans
