class Solution:
    def validSubarrays(self, nums):
        ans = 0
        stack = []
        for i, num in enumerate(nums):
            while stack and nums[stack[-1]] > num:
                stack.pop()
            stack.append(i)
            ans += len(stack)
        return ans
