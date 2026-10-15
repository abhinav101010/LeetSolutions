from typing import List

class Solution:
    def cheapestJump(self, A: List[int], B: int) -> List[int]:
        n = len(A)
        if n == 0 or A[0] == -1 or A[-1] == -1:
            return []
        INF = float('inf')
        dp_cost = [INF] * n
        dp_path = [[] for _ in range(n)]
        dp_cost[0] = A[0]
        dp_path[0] = [1]  # 1-indexed
        for i in range(1, n):
            if A[i] == -1:
                continue
            for j in range(max(0, i - B), i):
                if dp_cost[j] == INF:
                    continue
                cand_cost = dp_cost[j] + A[i]
                cand_path = dp_path[j] + [i + 1]
                if cand_cost < dp_cost[i] or (cand_cost == dp_cost[i] and cand_path < dp_path[i]):
                    dp_cost[i] = cand_cost
                    dp_path[i] = cand_path
        if dp_cost[-1] == INF:
            return []
        return dp_path[-1]
