from typing import List

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mod_map = {0: -1}
        prefix_sum = 0
        
        for i, num in enumerate(nums):
            prefix_sum += num
            mod = prefix_sum % k
            if mod in mod_map:
                if i - mod_map[mod] >= 2:
                    return True
            else:
                mod_map[mod] = i
        
        return False