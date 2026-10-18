class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        v, h = destination
        ans = []
        for i in range(v + h):
            if not h:
                ans.append('V')
                v -= 1
                continue
            if not v:
                ans.append('H')
                h -= 1
                continue
            combinations = comb(v + h - 1, h - 1)
            if k <= combinations:
                ans.append('H')
                h -= 1
            else:
                ans.append('V')
                v -= 1
                k -= combinations
        return ''.join(ans)

import math
import bisect
import heapq
import functools
import copy
import math as m
import bisect
import heapq
import sys
sys.setrecursionlimit(10**7)

from math import comb
from functools import reduce
