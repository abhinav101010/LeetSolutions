#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        vector<int> tmp(n, INF);
        dist[src] = 0;
        for (int i = 0; i <= K; i++) {
            fill(tmp.begin(), tmp.end(), INF);
            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if (dist[u] == INF) continue;
                if (dist[u] + w < tmp[v]) {
                    tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
