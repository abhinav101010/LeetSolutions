#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            graph[u].push_back({v, c + 1});
            graph[v].push_back({u, c + 1});
        }
        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : graph[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        // count original nodes reachable
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans++;
        }
        // count new nodes on edges
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long long uReach = max(0LL, (long long)maxMoves - dist[u]);
            long long vReach = max(0LL, (long long)maxMoves - dist[v]);
            ans += min(cnt, (int)(uReach + vReach));
        }
        return ans;
    }
};
