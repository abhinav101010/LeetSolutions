#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, vector<pair<int,int>>& cells) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
        visited[i][j] = true;
        cells.push_back({i, j});
        dfs(grid, visited, i+1, j, cells);
        dfs(grid, visited, i-1, j, cells);
        dfs(grid, visited, i, j+1, cells);
        dfs(grid, visited, i, j-1, cells);
    }
    
    vector<pair<int,int>> transform(const vector<pair<int,int>>& points, int rot, bool reflect) {
        vector<pair<int,int>> res;
        for (auto p : points) {
            int x = p.first, y = p.second;
            int xr = x, yr = y;
            for (int r = 0; r < rot; r++) {
                int tmp = xr;
                xr = yr;
                yr = -tmp;
            }
            if (reflect) {
                xr = -xr;
            }
            res.push_back({xr, yr});
        }
        return res;
    }
    
    string normalize(const vector<pair<int,int>>& shape) {
        int minx = INT_MAX, miny = INT_MAX;
        for (auto p : shape) {
            if (p.first < minx) minx = p.first;
            if (p.second < miny) miny = p.second;
        }
        vector<pair<int,int>> shifted;
        for (auto p : shape) {
            shifted.push_back({p.first - minx, p.second - miny});
        }
        sort(shifted.begin(), shifted.end());
        string sb;
        for (size_t i = 0; i < shifted.size(); ++i) {
            if (i > 0) sb.append(":");
            sb.append(to_string(shifted[i].first)).append(",").append(to_string(shifted[i].second));
        }
        return sb;
    }
    
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        set<string> signatures;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int,int>> cells;
                    dfs(grid, visited, i, j, cells);
                    string minSig = "";
                    bool first = true;
                    for (int rot = 0; rot < 4; rot++) {
                        for (int reflect = 0; reflect < 2; reflect++) {
                            auto t = transform(cells, rot, reflect == 1);
                            string norm = normalize(t);
                            if (first || norm < minSig) {
                                minSig = norm;
                                first = false;
                            }
                        }
                    }
                    signatures.insert(minSig);
                }
            }
        }
        return signatures.size();
    }
};
