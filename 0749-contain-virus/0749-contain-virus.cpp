#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
    struct Region {
        vector<pair<int,int>> cells;
        unordered_set<string> threatened;
        int walls;
    };
    
    Region bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int si, int sj, int n, int m, vector<pair<int,int>>& dirs) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        visited[si][sj] = true;
        Region reg;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;
            reg.cells.push_back({x, y});
            for (auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (grid[nx][ny] == 1) {
                        if (!visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    } else { // uninfected
                        string key = to_string(nx) + "," + to_string(ny);
                        reg.threatened.insert(key);
                        reg.walls++;
                    }
                }
                // out of bounds: no wall
            }
        }
        return reg;
    }
    
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int n = isInfected.size();
        int m = isInfected[0].size();
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;
        
        while (true) {
            // find regions
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            vector<Region> regions;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        Region reg = bfs(isInfected, visited, i, j, n, m, dirs);
                        regions.push_back(reg);
                    }
                }
            }
            if (regions.empty()) break;
            
            // find region with max threatened cells
            int maxThreat = -1;
            int idx = -1;
            for (int i = 0; i < (int)regions.size(); i++) {
                int threat = (int)regions[i].threatened.size();
                if (threat > maxThreat) {
                    maxThreat = threat;
                    idx = i;
                }
            }
            if (maxThreat == 0) break; // no spread possible
            
            // add walls for selected region
            ans += regions[idx].walls;
            
            // spread virus from other regions, contain selected region
            for (int i = 0; i < (int)regions.size(); i++) {
                Region& reg = regions[i];
                if (i == idx) {
                    // contain: mark as 2
                    for (auto& p : reg.cells) {
                        isInfected[p.first][p.second] = 2;
                    }
                } else {
                    // spread
                    for (auto& p : reg.cells) {
                        int x = p.first;
                        int y = p.second;
                        for (auto& dir : dirs) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && isInfected[nx][ny] == 0) {
                                isInfected[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
