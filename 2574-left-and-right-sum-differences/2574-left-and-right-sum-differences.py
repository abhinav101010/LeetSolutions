class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        leftSum = [0]
        rightSum = [sum(nums)-nums[0]]
        n = len(nums)
        for i in range(n):
            if i != 0:
                leftSum.append(leftSum[-1]+nums[i])
            rightSum.append(rightSum[-1]-nums[i])

        return [abs(leftSum[i] - rightSum[i]) for i in range(n)]