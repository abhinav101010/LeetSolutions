class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        
        int n = prices.size();
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
        
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);
        
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {
                buy[t] = max(buy[t], sell[t - 1] - prices[i]);
                sell[t] = max(sell[t], buy[t] + prices[i]);
            }
        }
        
        return sell[k];
    }
};