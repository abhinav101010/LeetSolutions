#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2, vector<vector<vector<int>>>& memo, int n) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            return INT_MIN;
        }
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n-1 && c1 == n-1) {
            return grid[r1][c1];
        }
        if (memo[r1][c1][r2] != INT_MIN) {
            return memo[r1][c1][r2];
        }
        int cherry = grid[r1][c1];
        if (r1 != r2 || c1 != c2) {
            cherry += grid[r2][c2];
        }
        int maxNext = INT_MIN;
        for (int nr1 : {r1+1, r1}) {
            for (int nr2 : {r2+1, r2}) {
                int nc1 = c1 + (nr1 - r1);
                int nc2 = c2 + (nr2 - r2);
                int val = dfs(grid, nr1, nc1, nr2, memo, n);
                if (val > maxNext) {
                    maxNext = val;
                }
            }
        }
        int res = cherry + maxNext;
        memo[r1][c1][r2] = res;
        return res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        int ans = dfs(grid, 0, 0, 0, memo, n);
        return max(ans, 0);
    }
};
