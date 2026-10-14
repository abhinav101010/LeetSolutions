import random
from typing import List

class Solution:
    def __init__(self, N: int, blacklist: List[int]):
        self.m = N - len(blacklist)
        self.blackset = set(b for b in blacklist if b < self.m)
        self.map = {}
        j = self.m
        for b in blacklist:
            if b >= self.m:
                continue
            while j in self.blackset or j in self.map:
                j += 1
            self.map[b] = j
            j += 1

    def pick(self) -> int:
        x = random.randint(0, self.m - 1)
        return self.map.get(x, x)
