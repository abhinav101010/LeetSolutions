#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    vector<ll> dijkstra(int n, const vector<vector<pair<int,ll>>>& g, int start) {
        vector<ll> dist(n, LLONG_MAX / 4);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& edge : g[u]) {
                int v = edge.first;
                ll w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,ll>>> g(n);
        vector<vector<pair<int,ll>>> rg(n);
        for (auto& e : edges) {
            int f = e[0], t = e[1];
            ll w = e[2];
            g[f].push_back({t, w});
            rg[t].push_back({f, w});
        }
        vector<ll> d1 = dijkstra(n, g, src1);
        vector<ll> d2 = dijkstra(n, g, src2);
        vector<ll> d3 = dijkstra(n, rg, dest);
        ll ans = LLONG_MAX / 4;
        for (int i = 0; i < n; ++i) {
            if (d1[i] >= LLONG_MAX / 4 || d2[i] >= LLONG_MAX / 4 || d3[i] >= LLONG_MAX / 4) continue;
            ll t = d1[i] + d2[i] + d3[i];
            if (t < ans) ans = t;
        }
        if (ans >= LLONG_MAX / 4) return -1;
        return ans;
    }
};
