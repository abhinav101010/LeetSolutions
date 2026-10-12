import java.util.*;

class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length == 0 || k == 0) return 0;
        
        int n = prices.length;
        if (k >= n / 2) {
            // Unlimited transactions
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        
        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];
        Arrays.fill(buy, -prices[0]);
        
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {
                buy[t] = Math.max(buy[t], sell[t - 1] - prices[i]);
                sell[t] = Math.max(sell[t], buy[t] + prices[i]);
            }
        }
        
        return sell[k];
    }
}