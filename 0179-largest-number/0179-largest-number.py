from functools import cmp_to_key
from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def compare(x, y):
            if x + y > y + x:
                return -1
            elif x + y < y + x:
                return 1
            return 0
        
        nums_str = list(map(str, nums))
        nums_str.sort(key=cmp_to_key(compare))
        result = ''.join(nums_str)
        return '0' if result[0] == '0' else result