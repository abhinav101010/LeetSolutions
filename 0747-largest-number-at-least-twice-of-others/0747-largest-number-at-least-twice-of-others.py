class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        newNums = sorted(nums)
        return nums.index(newNums[-1]) if newNums[-1] >= 2*newNums[-2] else -1