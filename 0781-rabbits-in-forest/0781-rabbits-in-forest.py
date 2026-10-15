from typing import List
from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cnt = Counter(answers)
        total = 0
        for x, f in cnt.items():
            group_size = x + 1
            groups = (f + group_size - 1) // group_size  # ceil division
            total += groups * group_size
        return total
