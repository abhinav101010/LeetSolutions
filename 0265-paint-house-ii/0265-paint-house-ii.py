from typing import List

class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if not costs or not costs[0]:
            return 0
        n = len(costs)
        k = len(costs[0])
        # dp for the previous house
        prev = costs[0][:]
        for i in range(1, n):
            curr = [0] * k
            # find the smallest and second smallest in prev
            min1 = float('inf')
            min2 = float('inf')
            idx = -1
            for j in range(k):
                if prev[j] < min1:
                    min2 = min1
                    min1 = prev[j]
                    idx = j
                elif prev[j] < min2:
                    min2 = prev[j]
            for j in range(k):
                if j == idx:
                    curr[j] = min2 + costs[i][j]
                else:
                    curr[j] = min1 + costs[i][j]
            prev = curr
        return min(prev)
