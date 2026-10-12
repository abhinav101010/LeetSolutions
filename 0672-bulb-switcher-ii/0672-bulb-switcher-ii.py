from functools import lru_cache

class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        if presses == 0:
            return 1
        if presses == 1:
            return 2 if n >= 2 else 1
        if presses == 2:
            if n == 1: return 2
            if n == 2: return 3
            return 4
        # presses >= 3
        if n == 1: return 2
        if n == 2: return 4
        return 8