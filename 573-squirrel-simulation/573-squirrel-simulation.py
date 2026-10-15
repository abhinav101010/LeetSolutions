from typing import List

class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        def dist(a, b):
            return abs(a[0]-b[0]) + abs(a[1]-b[1])
        total = 0
        max_save = 0
        for nut in nuts:
            d_tree = dist(tree, nut)
            total += 2 * d_tree
            save = d_tree - dist(squirrel, nut)
            if save > max_save:
                max_save = save
        return total - max_save
