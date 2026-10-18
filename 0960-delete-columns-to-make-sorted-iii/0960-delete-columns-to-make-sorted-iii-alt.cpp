#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxKeep = 0;
        for (int v : dp) {
            maxKeep = max(maxKeep, v);
        }
        return m - maxKeep;
    }
};
