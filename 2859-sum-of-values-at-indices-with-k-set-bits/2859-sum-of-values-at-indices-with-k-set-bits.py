class Solution:
    def sumIndicesWithKSetBits(self, nums, k) :
        return sum(x for i, x in enumerate(nums) if i.bit_count() == k)
