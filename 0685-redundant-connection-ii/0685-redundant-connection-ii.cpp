class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        vector<int> parentEdge(n + 1, -1);
        int candidate1 = -1, candidate2 = -1;
        for (int i = 0; i < (int)edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            if (parentEdge[b] != -1) {
                candidate1 = parentEdge[b];
                candidate2 = i;
                continue;
            }
            parentEdge[b] = i;
        }
        for (int i = 0; i <= n; i++) parent[i] = i;
        for (int i = 0; i < (int)edges.size(); i++) {
            if (i == candidate2) continue;
            int a = edges[i][0], b = edges[i][1];
            if (find(a) == find(b)) {
                return candidate1 == -1 ? edges[i] : edges[candidate1];
            }
            parent[find(b)] = find(a);
        }
        return edges[candidate2];
    }
};