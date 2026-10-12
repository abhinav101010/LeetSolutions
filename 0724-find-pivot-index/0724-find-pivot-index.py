class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        rightSum = sum(nums)
        leftSum = 0

        for i in range(len(nums)):
            leftSum+=nums[i]
            rightSum-=nums[i]
            if leftSum-nums[i] == rightSum:
                return i
        
        return -1