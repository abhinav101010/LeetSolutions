from typing import List

class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        
        min_left = [0] * len(nums)
        min_left[0] = nums[0]
        for i in range(1, len(nums)):
            min_left[i] = min(min_left[i-1], nums[i])
        
        stack = []
        for j in range(len(nums) - 1, -1, -1):
            if nums[j] > min_left[j]:
                while stack and stack[-1] <= min_left[j]:
                    stack.pop()
                if stack and stack[-1] < nums[j]:
                    return True
                stack.append(nums[j])
        return False