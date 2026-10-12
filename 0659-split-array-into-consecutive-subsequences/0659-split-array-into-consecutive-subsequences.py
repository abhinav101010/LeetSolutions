from typing import List
from collections import defaultdict

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        count = defaultdict(int)
        for n in nums:
            count[n] += 1
        
        tails = defaultdict(int)
        for n in nums:
            if count[n] == 0:
                continue
            if tails[n - 1] > 0:
                tails[n - 1] -= 1
                tails[n] += 1
            elif count[n + 1] > 0 and count[n + 2] > 0:
                count[n + 1] -= 1
                count[n + 2] -= 1
                tails[n + 2] += 1
            else:
                return False
            count[n] -= 1
        return True