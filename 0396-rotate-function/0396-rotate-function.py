from typing import List

class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        total = sum(nums)
        curr = sum(i * nums[i] for i in range(n))
        max_val = curr
        
        for i in range(n - 1, 0, -1):
            curr = curr + total - n * nums[i]
            max_val = max(max_val, curr)
        
        return max_val