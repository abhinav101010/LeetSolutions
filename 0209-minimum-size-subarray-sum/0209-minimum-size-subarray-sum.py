class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
# Gives TLE
        # ans = float("inf")

        # for i in range(len(nums)):
        #     currSum = 0
        #     for j in range(i, len(nums)):
        #         currSum += nums[j]

        #         if currSum >= target:
        #             ans = min(ans, j - i + 1)
        #             break

        # return 0 if ans == float("inf") else ans

        left = 0
        currSum = 0
        ans = float("inf")
        for right in range(len(nums)):
            currSum += nums[right]
            while currSum >= target:
                ans = min(ans, right - left + 1)
                currSum -= nums[left]
                left += 1
        return 0 if ans == float("inf") else ans