from typing import List
from functools import lru_cache

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + [x for x in nums if x > 0] + [1]
        n = len(nums)
        
        @lru_cache(None)
        def dp(left: int, right: int) -> int:
            if left + 1 == right:
                return 0
            return max(nums[left] * nums[i] * nums[right] + dp(left, i) + dp(i, right)
                       for i in range(left + 1, right))
        
        return dp(0, n - 1)