import random
from typing import List

class Solution:
    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.areas = []
        self.total = 0
        for x1, y1, x2, y2 in rects:
            area = (x2 - x1 + 1) * (y2 - y1 + 1)
            self.total += area
            self.areas.append(self.total)

    def pick(self) -> List[int]:
        rand = random.randint(1, self.total)
        left, right = 0, len(self.areas) - 1
        while left < right:
            mid = (left + right) // 2
            if self.areas[mid] < rand:
                left = mid + 1
            else:
                right = mid
        
        x1, y1, x2, y2 = self.rects[left]
        x = random.randint(x1, x2)
        y = random.randint(y1, y2)
        return [x, y]