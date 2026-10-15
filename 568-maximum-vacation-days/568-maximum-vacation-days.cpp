#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<vector<int>> dp(n, vector<int>(k, INT_MIN));
        // week 0
        for (int c = 0; c < n; c++) {
            if (c == 0 || flights[0][c] == 1) {
                dp[c][0] = days[c][0];
            }
        }
        for (int w = 1; w < k; w++) {
            for (int c = 0; c < n; c++) {
                int best = INT_MIN;
                for (int pc = 0; pc < n; pc++) {
                    if ((pc == c || flights[pc][c] == 1) && dp[pc][w-1] != INT_MIN) {
                        best = max(best, dp[pc][w-1] + days[c][w]);
                    }
                }
                dp[c][w] = best;
            }
        }
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = max(ans, dp[c][k-1]);
        }
        return ans;
    }
};
