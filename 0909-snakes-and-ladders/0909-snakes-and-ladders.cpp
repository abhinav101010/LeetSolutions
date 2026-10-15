#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto get_coord = [&](int s) -> pair<int,int> {
            int s0 = s - 1;
            int quot = s0 / n;
            int rem = s0 % n;
            int r = n - 1 - quot;
            int c = ((n - 1 - quot) % 2 == 0) ? rem : n - 1 - rem;
            return {r, c};
        };
        vector<bool> visited(n*n + 1, false);
        queue<pair<int,int>> q; // position, steps
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty()) {
            auto [s, steps] = q.front(); q.pop();
            if (s == n*n) return steps;
            for (int nxt = s+1; nxt <= min(s+6, n*n); nxt++) {
                auto [r, c] = get_coord(nxt);
                if (board[r][c] != -1) {
                    nxt = board[r][c];
                }
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push({nxt, steps+1});
                }
            }
        }
        return -1;
    }
};
