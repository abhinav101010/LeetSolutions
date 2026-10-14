from typing import List

class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        from collections import defaultdict
        bal = defaultdict(int)
        for x, y, z in transactions:
            bal[x] -= z
            bal[y] += z
        debts = [v for v in bal.values() if v != 0]
        n = len(debts)
        # dfs
        def dfs(start):
            while start < n and debts[start] == 0:
                start += 1
            if start == n:
                return 0
            res = float('inf')
            seen = set()
            for i in range(start + 1, n):
                if debts[i] * debts[start] < 0 and debts[i] not in seen:
                    seen.add(debts[i])
                    debts[i] += debts[start]
                    res = min(res, 1 + dfs(start + 1))
                    debts[i] -= debts[start]
            return res
        return dfs(0)
