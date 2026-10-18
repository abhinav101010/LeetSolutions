class Solution:
    def numberOfPairs(self, nums1, nums2, k) -> int:
        return sum(x % (y * k) == 0 for x in nums1 for y in nums2)
