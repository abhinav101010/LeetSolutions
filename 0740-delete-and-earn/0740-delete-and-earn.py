from typing import List

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_val = max(nums)
        freq = [0] * (max_val + 1)
        for x in nums:
            freq[x] += x
        # house robber
        take = 0
        skip = 0
        for v in freq:
            new_take = skip + v
            new_skip = max(take, skip)
            take = new_take
            skip = new_skip
        return max(take, skip)
