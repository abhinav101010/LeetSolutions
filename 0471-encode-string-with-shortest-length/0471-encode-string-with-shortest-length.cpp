#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n, ""));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = s.substr(i, len);
                if (len > 4) {
                    for (int k = i; k < j; ++k) {
                        int mid = k - i + 1;
                        if (len % mid == 0) {
                            string pattern = s.substr(i, mid);
                            bool isRepeated = true;
                            for (int t = 1; t < len / mid; ++t) {
                                if (s.substr(i + t * mid, mid) != pattern) {
                                    isRepeated = false;
                                    break;
                                }
                            }
                            if (isRepeated) {
                                string candidate = to_string(len / mid) + "[" + dp[i][k] + "]";
                                if (candidate.size() < dp[i][j].size()) {
                                    dp[i][j] = candidate;
                                }
                            }
                        }
                    }
                    for (int k = i; k < j; ++k) {
                        if (dp[i][k].size() + dp[k + 1][j].size() < dp[i][j].size()) {
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
