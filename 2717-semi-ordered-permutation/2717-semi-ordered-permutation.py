class Solution:
    def semiOrderedPermutation(self, nums) -> int:
        n = len(nums)
        i = nums.index(1)
        j = nums.index(n)
        k = 1 if i < j else 2
        return i + n - j - k
