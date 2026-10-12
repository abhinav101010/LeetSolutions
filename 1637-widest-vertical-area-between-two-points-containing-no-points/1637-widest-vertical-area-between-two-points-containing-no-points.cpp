class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        x.reserve(points.size());

        for (const auto& p : points) {
            x.push_back(p[0]);
        }

        sort(x.begin(), x.end());

        int ans = 0;
        for (int i = 1; i < (int)x.size(); i++) {
            ans = max(ans, x[i] - x[i - 1]);
        }

        return ans;
    }
};