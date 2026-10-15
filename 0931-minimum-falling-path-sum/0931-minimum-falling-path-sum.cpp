#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> dp(A[0].begin(), A[0].end());
        for (int r = 1; r < n; r++) {
            vector<int> newDp(n);
            for (int c = 0; c < n; c++) {
                int best = dp[c];
                if (c > 0) best = min(best, dp[c-1]);
                if (c < n-1) best = min(best, dp[c+1]);
                newDp[c] = A[r][c] + best;
            }
            dp = move(newDp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
