#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        const int MOD = 1000000007;
        int n = S.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        vector<vector<int>> next(n, vector<int>(4, n));
        vector<vector<int>> prev(n, vector<int>(4, -1));
        for (int c = 0; c < 4; c++) {
            char ch = 'a' + c;
            int nxt = n;
            for (int i = n-1; i >= 0; i--) {
                if (S[i] == ch) nxt = i;
                next[i][c] = nxt;
            }
            int prv = -1;
            for (int i = 0; i < n; i++) {
                if (S[i] == ch) prv = i;
                prev[i][c] = prv;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (S[i] != S[j]) {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                } else {
                    int ch = S[i] - 'a';
                    int left = next[i][ch];
                    int right = prev[j][ch];
                    if (left > right) {
                        dp[i][j] = (dp[i+1][j-1] * 2LL + 2) % MOD;
                    } else if (left == right) {
                        dp[i][j] = (dp[i+1][j-1] * 2LL + 1) % MOD;
                    } else {
                        long long val = (long long)dp[i+1][j-1] * 2 - dp[left+1][right-1];
                        dp[i][j] = (val % MOD + MOD) % MOD;
                    }
                }
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
        return dp[0][n-1];
    }
};
