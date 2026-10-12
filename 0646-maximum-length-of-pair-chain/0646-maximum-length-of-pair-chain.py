from typing import List

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        cur_end = -10**9
        count = 0
        for a, b in pairs:
            if a > cur_end:
                count += 1
                cur_end = b
            elif b < cur_end:
                cur_end = b
        return count