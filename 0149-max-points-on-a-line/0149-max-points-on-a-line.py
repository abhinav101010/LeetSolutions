from typing import List
from math import gcd
from collections import defaultdict

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n
        
        max_points = 0
        
        for i in range(n):
            slopes = defaultdict(int)
            same = 1
            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                
                if dx == 0 and dy == 0:
                    same += 1
                else:
                    g = gcd(dx, dy)
                    dx //= g
                    dy //= g
                    if dx < 0:
                        dx = -dx
                        dy = -dy
                    slopes[(dx, dy)] += 1
            
            current_max = same
            for count in slopes.values():
                current_max = max(current_max, count + same)
            max_points = max(max_points, current_max)
        
        return max_points