class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
        total = 0
        max_diff = -inf
        for nut in nuts:
            d = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1])
            total += 2 * d
            d2 = abs(squirrel[0] - nut[0]) + abs(squirrel[1] - nut[1])
            max_diff = max(max_diff, d - d2)
        return total - max_diff
