#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        queue<pair<int,int>> q;
        bool found = false;
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= n || A[r][c] != 1) return;
            A[r][c] = 2;
            q.push({r, c});
            dfs(r+1, c);
            dfs(r-1, c);
            dfs(r, c+1);
            dfs(r, c-1);
        };
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (A[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }
        int steps = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (A[nr][nc] == 1) {
                            return steps;
                        }
                        if (A[nr][nc] == 0) {
                            A[nr][nc] = 2;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
