class Solution:
    def absDifference(self, nums, k):
        nums.sort()
        return sum(nums[-k:]) - sum(nums[:k])
