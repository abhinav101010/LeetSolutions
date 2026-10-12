from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        stack = []
        
        for i in range(2 * n - 1, -1, -1):
            idx = i % n
            while stack and stack[-1] <= nums[idx]:
                stack.pop()
            if i < n and stack:
                result[idx] = stack[-1]
            stack.append(nums[idx])
        
        return result