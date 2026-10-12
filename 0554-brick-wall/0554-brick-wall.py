from collections import Counter
from typing import List

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        edges = Counter()
        for row in wall:
            pos = 0
            for brick in row[:-1]:
                pos += brick
                edges[pos] += 1
        max_edges = max(edges.values()) if edges else 0
        return len(wall) - max_edges