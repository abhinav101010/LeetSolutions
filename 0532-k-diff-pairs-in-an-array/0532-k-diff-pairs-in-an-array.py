from typing import List
from collections import Counter

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        count = Counter(nums)
        result = 0
        if k == 0:
            for v in count.values():
                if v > 1:
                    result += 1
        else:
            for num in count:
                if num + k in count:
                    result += 1
        return result