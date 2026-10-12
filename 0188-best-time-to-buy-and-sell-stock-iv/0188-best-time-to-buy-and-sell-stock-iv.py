from typing import List

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices or k == 0:
            return 0
        
        n = len(prices)
        if k >= n // 2:
            # Unlimited transactions
            profit = 0
            for i in range(1, n):
                if prices[i] > prices[i - 1]:
                    profit += prices[i] - prices[i - 1]
            return profit
        
        # DP: dp[t][i] = max profit with at most t transactions up to day i
        buy = [-prices[0]] * (k + 1)
        sell = [0] * (k + 1)
        
        for i in range(1, n):
            for t in range(1, k + 1):
                buy[t] = max(buy[t], sell[t - 1] - prices[i])
                sell[t] = max(sell[t], buy[t] + prices[i])
        
        return sell[k]