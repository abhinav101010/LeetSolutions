class Solution:
    def findIntersectionValues(self, nums1, nums2) :
        s1, s2 = set(nums1), set(nums2)
        return [sum(x in s2 for x in nums1), sum(x in s1 for x in nums2)]
