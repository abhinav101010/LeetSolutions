class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort()
        duplicate = -1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                duplicate = nums[i]
                break

        for i in range(1, len(nums)+1):
            if i not in nums:
                return [duplicate, i]