#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        unordered_set<int> visitedRoutes;
        queue<pair<int,int>> q; // route index, buses taken
        for (int rt : stopToRoutes[source]) {
            q.push({rt, 1});
            visitedRoutes.insert(rt);
        }
        unordered_set<int> targetRoutes(stopToRoutes[target].begin(), stopToRoutes[target].end());
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int rt = cur.first;
            int buses = cur.second;
            if (targetRoutes.find(rt) != targetRoutes.end()) {
                return buses;
            }
            for (int stop : routes[rt]) {
                for (int nxtRt : stopToRoutes[stop]) {
                    if (visitedRoutes.find(nxtRt) == visitedRoutes.end()) {
                        visitedRoutes.insert(nxtRt);
                        q.push({nxtRt, buses + 1});
                    }
                }
            }
        }
        return -1;
    }
};
