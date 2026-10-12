class Solution {
private:
    static const int MOD = 1000000007;
    
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1; // no inverse pairs
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
                }
            }
        }
        
        return dp[n][k];
    }
};