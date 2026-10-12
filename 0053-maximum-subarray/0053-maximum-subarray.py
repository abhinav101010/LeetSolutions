class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
# Gave TLE: tought self
        # ans = nums[0]
        # n = len(nums)
        # for i in range(n):
        #     for j in range(i+1, n+1):
        #         ans = max(ans, sum(nums[i:j]))
        # return ans

        # ans = num[0]
        # left, right = 0, len(nums)-1

# not usefull
        # while right>=left:
        #     ans = max(ans, sum(nums[left:right+1]))
        #     if nums[right] == nums[left]:
        #         left+=1
        #         right-=1
        #     elif nums[right] > nums[left]:
        #         left+=1
        #     elif nums[left] > nums[right]:
        #         right-=1
        # return ans

# Kadane’s Algorithm
        curr = best = nums[0]

        for i in range(1, len(nums)):
            curr = max(nums[i], curr + nums[i])
            best = max(best, curr)

        return best