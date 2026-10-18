class Solution:
    def findValueOfPartition(self, nums) :
        nums.sort()
        return min(b - a for a, b in pairwise(nums))
