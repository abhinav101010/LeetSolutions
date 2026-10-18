class Solution:
    def canDivideIntoSubsequences(self, nums, k):
        from collections import Counter
        mx=max(Counter(nums).values())
        return mx*k<=len(nums)
