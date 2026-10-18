class Solution:
    def finalElement(self, nums) -> int:
        return max(nums[0], nums[-1])
