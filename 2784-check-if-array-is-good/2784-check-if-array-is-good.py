class Solution:
    def isGood(self, nums: List[int]) -> bool:
        nums.sort()
        print(nums[:-2])
        if nums[-1] != len(nums)-1 or nums[-2] != len(nums)-1 or (len(nums) > 2 and nums[:-2] != list(range(1, nums[-3]+1))):
            return False
        return True