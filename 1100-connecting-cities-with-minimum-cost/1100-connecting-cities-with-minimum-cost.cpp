#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<int> parent;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        parent[rx] = ry; return true;
    }
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto& a, auto& b){ return a[2] < b[2]; });
        parent.resize(N + 1);
        for (int i = 0; i <= N; i++) parent[i] = i;
        int cost = 0, edges = 0;
        for (auto& c : connections) {
            if (unite(c[0], c[1])) { cost += c[2]; edges++; }
        }
        return edges == N - 1 ? cost : -1;
    }
};
