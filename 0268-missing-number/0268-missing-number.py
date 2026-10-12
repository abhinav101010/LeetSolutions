class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # Self thought logic with Sn formula
        n = len(nums)
        return n * (n + 1) // 2 - sum(nums)