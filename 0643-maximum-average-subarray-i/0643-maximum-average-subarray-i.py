class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        window = sum(nums[:k])
        maxSum = window

        for i in range(k, len(nums)):
            window += nums[i]
            window -= nums[i-k]

            maxSum = max(maxSum, window)

        return maxSum / k