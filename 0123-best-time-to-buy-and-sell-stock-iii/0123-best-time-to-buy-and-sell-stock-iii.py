from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        n = len(prices)
        # Four states: buy1, sell1, buy2, sell2
        buy1 = -prices[0]
        sell1 = 0
        buy2 = -prices[0]
        sell2 = 0
        
        for i in range(1, n):
            price = prices[i]
            buy1 = max(buy1, -price)
            sell1 = max(sell1, buy1 + price)
            buy2 = max(buy2, sell1 - price)
            sell2 = max(sell2, buy2 + price)
        
        return sell2