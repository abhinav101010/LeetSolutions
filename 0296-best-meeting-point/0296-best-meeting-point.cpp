class Solution {
public:
    int getDistance(vector<int>& points) {
        int res = 0;
        int l = 0, r = points.size() - 1;
        while (l < r) {
            res += points[r--] - points[l++];
        }
        return res;
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows, cols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        }
        return getDistance(rows) + getDistance(cols);
    }
};