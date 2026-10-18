class Solution:
    def uniqueXorTriplets(self, nums) -> int:
        n = len(nums)
        return n if n <= 2 else 1 << n.bit_length()
