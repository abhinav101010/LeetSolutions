from collections import defaultdict
from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        count[0] = 1
        prefix_sum = 0
        result = 0
        
        for num in nums:
            prefix_sum += num
            result += count[prefix_sum - k]
            count[prefix_sum] += 1
        
        return result