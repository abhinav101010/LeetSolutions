#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                cnt += grid[i][j];
            }
            cnt = max(cnt, m - cnt);
            ans += cnt * (1 << (n - 1 - j));
        }
        return ans;
    }
};
