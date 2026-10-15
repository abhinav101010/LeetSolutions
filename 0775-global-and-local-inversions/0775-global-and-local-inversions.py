from typing import List

class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i, val in enumerate(A):
            if abs(val - i) > 1:
                return False
        return True
