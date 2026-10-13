from typing import List

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0
        dp = [costs[0][i] for i in range(3)]
        for i in range(1, len(costs)):
            dp_new = [0] * 3
            for j in range(3):
                dp_new[j] = costs[i][j] + min(dp[(j+1)%3], dp[(j+2)%3])
            dp = dp_new
        return min(dp)