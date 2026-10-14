#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }
        // Dijkstra
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int d = cur.first;
            int u = cur.second;
            if (d > dist[u]) continue;
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            if (dist[i] > maxDist) maxDist = dist[i];
        }
        return maxDist;
    }
};
