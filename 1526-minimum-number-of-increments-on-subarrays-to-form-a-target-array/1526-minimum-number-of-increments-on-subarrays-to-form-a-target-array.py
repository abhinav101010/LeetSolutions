class Solution:
    def minNumberOperations(self, target) -> int:
        return target[0] + sum(max(0, b - a) for a, b in pairwise(target))
