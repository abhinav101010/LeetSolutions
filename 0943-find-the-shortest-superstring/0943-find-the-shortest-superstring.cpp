#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                string a = A[i], b = A[j];
                int maxLen = min(a.size(), b.size());
                for (int k = maxLen; k >= 0; k--) {
                    if (a.substr(a.size() - k) == b.substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        vector<vector<string>> dp(1<<n, vector<string>(n, ""));
        for (int i = 0; i < n; i++) {
            dp[1<<i][i] = A[i];
        }
        for (int mask = 0; mask < (1<<n); mask++) {
            for (int last = 0; last < n; last++) {
                if ((mask & (1<<last)) == 0) continue;
                string cur = dp[mask][last];
                if (cur.empty()) continue;
                for (int nxt = 0; nxt < n; nxt++) {
                    if ((mask & (1<<nxt)) != 0) continue;
                    int mask2 = mask | (1<<nxt);
                    string cand = cur + A[nxt].substr(overlap[last][nxt]);
                    if (dp[mask2][nxt].empty() || cand.size() < dp[mask2][nxt].size() ||
                            (cand.size() == dp[mask2][nxt].size() && cand < dp[mask2][nxt])) {
                        dp[mask2][nxt] = cand;
                    }
                }
            }
        }
        int full = (1<<n) - 1;
        string ans;
        bool first = true;
        for (int last = 0; last < n; last++) {
            string s = dp[full][last];
            if (s.empty()) continue;
            if (first || s.size() < ans.size() ||
                    (s.size() == ans.size() && s < ans)) {
                ans = s;
                first = false;
            }
        }
        return ans;
    }
};
