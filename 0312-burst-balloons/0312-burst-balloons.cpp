class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums = {1};
        for (int x : nums) if (x > 0) newNums.push_back(x);
        newNums.push_back(1);
        
        int n = newNums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len < n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                        newNums[left] * newNums[i] * newNums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};