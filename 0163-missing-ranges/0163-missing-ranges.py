from typing import List

class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        res = []
        prev = lower - 1
        for num in nums + [upper + 1]:
            if num > prev + 1:
                l = prev + 1
                r = num - 1
                if l == r:
                    res.append(str(l))
                else:
                    res.append(f"{l}->{r}")
            prev = num
        return res