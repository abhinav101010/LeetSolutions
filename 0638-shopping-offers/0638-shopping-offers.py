from typing import List

class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        n = len(price)
        
        def dfs(needs):
            res = sum(price[i] * needs[i] for i in range(n))
            for offer in special:
                valid = True
                for i in range(n):
                    if needs[i] < offer[i]:
                        valid = False
                        break
                if valid:
                    new_needs = list(needs)
                    for i in range(n):
                        new_needs[i] -= offer[i]
                    res = min(res, offer[-1] + dfs(new_needs))
            return res
        
        return dfs(tuple(needs))