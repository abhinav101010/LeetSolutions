#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = string(1, s[i]);
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                string substr = s.substr(i, len);
                dp[i][j] = substr; // default
                // split
                for (int k = i; k < j; k++) {
                    string left = dp[i][k];
                    string right = dp[k+1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
                // check for repeated pattern
                int l = len;
                for (int p = 1; p <= l/2; p++) {
                    if (l % p == 0) {
                        int repeats = l / p;
                        string pattern = substr.substr(0, p);
                        bool ok = true;
                        for (int r = 1; r < repeats; r++) {
                            if (substr.substr(r*p, p) != pattern) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            string encodedPattern = dp[i][i+p-1];
                            string candidate = to_string(repeats) + "[" + encodedPattern + "]";
                            if (candidate.size() < dp[i][j].size()) {
                                dp[i][j] = candidate;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
