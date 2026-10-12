class Solution {
private:
    static const int MOD = 1000000007;
    
public:
    int numDecodings(string s) {
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= s.size(); i++) {
            char c = s[i - 1];
            if (c == '*') {
                dp[i] = (dp[i] + 9 * dp[i - 1]) % MOD;
            } else if (c != '0') {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
            
            if (i > 1) {
                char prev = s[i - 2];
                if (prev == '*' && c == '*') {
                    dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD;
                } else if (prev == '*') {
                    int val = c - '0';
                    if (val >= 0 && val <= 6) {
                        dp[i] = (dp[i] + 2 * dp[i - 2]) % MOD;
                    } else {
                        dp[i] = (dp[i] + dp[i - 2]) % MOD;
                    }
                } else if (c == '*') {
                    int p = prev - '0';
                    if (p == 1) {
                        dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD;
                    } else if (p == 2) {
                        dp[i] = (dp[i] + 6 * dp[i - 2]) % MOD;
                    }
                } else {
                    int num = (prev - '0') * 10 + (c - '0');
                    if (num >= 10 && num <= 26) {
                        dp[i] = (dp[i] + dp[i - 2]) % MOD;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};