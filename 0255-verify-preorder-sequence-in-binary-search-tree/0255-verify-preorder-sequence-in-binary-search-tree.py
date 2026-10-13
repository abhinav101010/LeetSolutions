from typing import List

class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        stack = []
        low = -10**10
        for val in preorder:
            if val < low:
                return False
            while stack and stack[-1] < val:
                low = stack.pop()
            stack.append(val)
        return True