#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> dp(k + 1, vector<int>(n, -1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = -1e9;
        }
        for (int week = 1; week <= k; ++week) {
            for (int city = 0; city < n; ++city) {
                dp[week][city] = dp[week - 1][city];
                for (int prev = 0; prev < n; ++prev) {
                    if (flights[prev][city]) {
                        dp[week][city] = max(dp[week][city], dp[week - 1][prev]);
                    }
                }
                dp[week][city] += days[city][week - 1];
            }
        }
        int res = 0;
        for (int city = 0; city < n; ++city) {
            res = max(res, dp[k][city]);
        }
        return res;
    }
};
