class Solution:
    def maxProfit(self, prices: List[int]) -> int:
# Self thought and implemented logic, Stand Proud
        maxProfit = 0
        bought = False
        n = len(prices)
        for i in range(n):
            if i < n-1:
                if prices[i] < prices[i+1] and not bought:
                    bought = True
                    maxProfit -= prices[i]
                    continue
                
                if prices[i] > prices[i+1] and bought:
                    bought = False
                    maxProfit += prices[i]
                    continue

            if bought and i == n-1:
                bought = False
                maxProfit += prices[i]

        return maxProfit