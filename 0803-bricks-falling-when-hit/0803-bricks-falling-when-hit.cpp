#include <vector>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        vector<int> parent(total + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> sz(total + 1, 1);

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
        auto idx = [&](int r, int c) { return r * n + c; };

        // grid after all hits applied
        vector<vector<int>> g = grid;
        for (auto& h : hits) {
            g[h[0]][h[1]] = 0;
        }

        // union remaining bricks, connect top row to virtual top node
        for (int c = 0; c < n; c++) {
            if (g[0][c] == 1) unite(idx(0, c), total);
        }
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] == 1) {
                    if (g[r-1][c] == 1) unite(idx(r, c), idx(r-1, c));
                    if (c > 0 && g[r][c-1] == 1) unite(idx(r, c), idx(r, c-1));
                }
            }
        }

        vector<int> res(hits.size(), 0);
        int prev = sz[find(total)];

        // process hits in reverse, adding bricks back
        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                res[i] = 0;
                continue;
            }
            g[r][c] = 1;
            if (r == 0) unite(idx(r, c), total);
            if (r > 0 && g[r-1][c] == 1) unite(idx(r, c), idx(r-1, c));
            if (r < m-1 && g[r+1][c] == 1) unite(idx(r, c), idx(r+1, c));
            if (c > 0 && g[r][c-1] == 1) unite(idx(r, c), idx(r, c-1));
            if (c < n-1 && g[r][c+1] == 1) unite(idx(r, c), idx(r, c+1));

            int curr = sz[find(total)];
            res[i] = max(0, curr - prev - 1);
            prev = curr;
        }
        return res;
    }
};