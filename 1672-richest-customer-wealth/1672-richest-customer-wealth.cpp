class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (const auto& row : accounts) {
            int sum = 0;
            for (int v : row) sum += v;
            ans = max(ans, sum);
        }
        return ans;
    }
};