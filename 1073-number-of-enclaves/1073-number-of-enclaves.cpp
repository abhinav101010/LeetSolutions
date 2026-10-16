#include <vector>
using namespace std;
class Solution {
    void dfs(vector<vector<int>>& g, int x, int y, int m, int n) {
        if (x<0||x>=m||y<0||y>=n||g[x][y]!=1) return;
        g[x][y] = 0;
        dfs(g,x+1,y,m,n); dfs(g,x-1,y,m,n); dfs(g,x,y+1,m,n); dfs(g,x,y-1,m,n);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
            if ((i==0||i==m-1||j==0||j==n-1) && grid[i][j]==1) dfs(grid,i,j,m,n);
        int ans = 0;
        for (auto& row : grid) for (int c : row) if (c == 1) ans++;
        return ans;
    }
};
