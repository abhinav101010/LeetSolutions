class Solution:
    def rob(self, nums: List[int]) -> int:
        # even = 0
        # odd = 0
        # for i in range(len(nums)):
        #     if i % 2 == 0:
        #         even+=nums[i]
        #         continue
        #     odd+=nums[i]
        # return max(even,odd)

        prev2 = 0
        prev1 = 0

        for money in nums:
            curr = max(prev1, prev2 + money)
            prev2 = prev1
            prev1 = curr

        return prev1