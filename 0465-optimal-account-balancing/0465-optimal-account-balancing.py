from typing import List
from collections import defaultdict

class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        balance = defaultdict(int)
        for a, b, amt in transactions:
            balance[a] -= amt
            balance[b] += amt
        debt = [v for v in balance.values() if v != 0]
        n = len(debt)
        memo = {}
        
        def dfs(i, cur):
            if i == n:
                return 0 if cur == 0 else float('inf')
            if (i, cur) in memo:
                return memo[(i, cur)]
            res = dfs(i + 1, cur)
            if cur == 0:
                res = min(res, dfs(i + 1, debt[i]))
            else:
                res = min(res, 1 + dfs(i + 1, cur + debt[i]))
            memo[(i, cur)] = res
            return res
        
        return dfs(0, 0)
