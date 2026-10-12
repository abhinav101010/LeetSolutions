class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;
        
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        queue<pair<int, int>> pacificQ, atlanticQ;
        
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pacificQ.emplace(i, 0);
            atlantic[i][n-1] = true;
            atlanticQ.emplace(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = true;
            pacificQ.emplace(0, j);
            atlantic[m-1][j] = true;
            atlanticQ.emplace(m-1, j);
        }
        
        bfs(heights, pacificQ, pacific);
        bfs(heights, atlanticQ, atlantic);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& queue, vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while (!queue.empty()) {
            auto [x, y] = queue.front();
            queue.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = true;
                    queue.emplace(nx, ny);
                }
            }
        }
    }
};