#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int N = n * 3;
        vector<vector<int>> g(N, vector<int>(N, 0));
        for (int r = 0; r < n; r++) {
            string row = grid[r];
            for (int c = 0; c < n; c++) {
                if (row[c] == '/') {
                    g[r*3][c*3+2] = 1;
                    g[r*3+1][c*3+1] = 1;
                    g[r*3+2][c*3] = 1;
                } else if (row[c] == '\\') {
                    g[r*3][c*3] = 1;
                    g[r*3+1][c*3+1] = 1;
                    g[r*3+2][c*3+2] = 1;
                }
                // else space: keep 0
            }
        }
        int ans = 0;
        function<void(int,int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= N || y < 0 || y >= N || g[x][y] != 0) return;
            g[x][y] = 1;
            dfs(x+1, y);
            dfs(x-1, y);
            dfs(x, y+1);
            dfs(x, y-1);
        };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][j] == 0) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};
