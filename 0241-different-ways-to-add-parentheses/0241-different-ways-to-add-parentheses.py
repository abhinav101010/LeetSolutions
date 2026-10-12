from typing import List
from functools import lru_cache

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        @lru_cache(None)
        def compute(expr: str) -> List[int]:
            if expr.isdigit():
                return [int(expr)]
            
            result = []
            for i, c in enumerate(expr):
                if c in '+-*':
                    left = compute(expr[:i])
                    right = compute(expr[i+1:])
                    for l in left:
                        for r in right:
                            if c == '+':
                                result.append(l + r)
                            elif c == '-':
                                result.append(l - r)
                            elif c == '*':
                                result.append(l * r)
            return result
        
        return compute(expression)