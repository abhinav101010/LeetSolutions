from typing import List

class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        max_xor = 0
        mask = 0
        
        for i in range(31, -1, -1):
            mask |= (1 << i)
            found = set()
            for num in nums:
                found.add(num & mask)
            
            candidate = max_xor | (1 << i)
            for prefix in found:
                if candidate ^ prefix in found:
                    max_xor = candidate
                    break
        
        return max_xor