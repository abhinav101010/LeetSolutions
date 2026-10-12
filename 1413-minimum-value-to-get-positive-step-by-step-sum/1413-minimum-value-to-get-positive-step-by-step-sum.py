class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        total = 0
        min_sum = 0

        for num in nums:
            total += num
            min_sum = min(min_sum, total)

        return 1 - min_sum
        