class Solution:
    def arithmeticTriplets(self, nums, diff):
        return sum(b - a == diff and c - b == diff for a, b, c in combinations(nums, 3))
