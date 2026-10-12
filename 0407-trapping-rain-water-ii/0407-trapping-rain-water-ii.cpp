class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        using T = tuple<int, int, int>; // height, x, y
        priority_queue<T, vector<T>, greater<T>> pq;
        
        for (int i = 0; i < m; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][n-1], i, n-1);
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[m-1][j], m-1, j);
            visited[0][j] = visited[m-1][j] = true;
        }
        
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int water = 0;
        
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    water += max(0, h - heightMap[nx][ny]);
                    pq.emplace(max(h, heightMap[nx][ny]), nx, ny);
                }
            }
        }
        
        return water;
    }
};