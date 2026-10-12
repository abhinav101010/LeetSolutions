from typing import List
from collections import Counter

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = Counter()
        dp[0] = 1
        
        for num in nums:
            next_dp = Counter()
            for s, count in dp.items():
                next_dp[s + num] += count
                next_dp[s - num] += count
            dp = next_dp
        
        return dp[target]