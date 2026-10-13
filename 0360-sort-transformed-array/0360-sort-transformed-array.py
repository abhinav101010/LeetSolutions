from typing import List

class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        res = [a * x * x + b * x + c for x in nums]
        res.sort()
        return res