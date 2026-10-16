from collections import defaultdict
class Solution:
    def minAreaFreeRect(self, points):
        n = len(points)
        # group by (center*2, dist2)
        groups = defaultdict(list)
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                cx2 = x1 + x2  # center * 2
                cy2 = y1 + y2
                dx = x1 - x2
                dy = y1 - y2
                dist2 = dx*dx + dy*dy
                groups[(cx2, cy2, dist2)].append((i, j))
        ans = float('inf')
        for key, pairs in groups.items():
            m = len(pairs)
            if m < 2:
                continue
            for i in range(m):
                x1, y1 = points[pairs[i][0]]
                x3, y3 = points[pairs[i][1]]
                for j in range(i+1, m):
                    x2, y2 = points[pairs[j][0]]
                    x4, y4 = points[pairs[j][1]]
                    # compute area using formula
                    area = abs((x1 - x3)*(y2 - y4) - (y1 - y3)*(x2 - x4)) / 2.0
                    if area > 0:
                        ans = min(ans, area)
        return 0 if ans == float('inf') else ans
