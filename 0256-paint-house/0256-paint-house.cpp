class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<int> dp = costs[0];
        for (int i = 1; i < costs.size(); i++) {
            vector<int> dpNew(3);
            dpNew[0] = costs[i][0] + min(dp[1], dp[2]);
            dpNew[1] = costs[i][1] + min(dp[0], dp[2]);
            dpNew[2] = costs[i][2] + min(dp[0], dp[1]);
            dp = dpNew;
        }
        return *min_element(dp.begin(), dp.end());
    }
};