class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        # print(costs)
        s = 0
        ans = 0
        for need in costs:
            if s+need <= coins:
                s += need
                ans+=1
            if s == coins:
                return ans
        return ans