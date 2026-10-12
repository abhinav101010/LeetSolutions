class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # nums.sort()
        # if nums[-1] <= 0: return 1
        # for i in range(1, nums[-1]+1):
        #     if i not in nums: return i
        # return nums[-1]+1


        nums.sort()
        if 1 not in nums: return 1
        for i in range(1, len(nums)):
            if nums[i-1] <= 0: continue
            if nums[i-1]+1 != nums[i] and nums[i-1]+1 != 0 and nums[i-1] != nums[i] :
                return nums[i-1]+1
        return nums[-1]+1