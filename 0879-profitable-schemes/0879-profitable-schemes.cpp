#include <vector>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1000000007;
        int len = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int k = 0; k < len; k++) {
            int g = group[k];
            int p = profit[k];
            for (int members = n; members >= g; members--) {
                for (int earn = minProfit; earn >= 0; earn--) {
                    int newEarn = min(minProfit, earn + p);
                    dp[members][newEarn] = (dp[members][newEarn] + dp[members - g][earn]) % MOD;
                }
            }
        }
        int total = 0;
        for (int members = 0; members <= n; members++) {
            total = (total + dp[members][minProfit]) % MOD;
        }
        return total;
    }
};
