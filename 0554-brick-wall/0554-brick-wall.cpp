class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        for (const auto& row : wall) {
            int pos = 0;
            for (int i = 0; i < (int)row.size() - 1; i++) {
                pos += row[i];
                edges[pos]++;
            }
        }
        int maxEdges = 0;
        for (auto& [_, v] : edges) maxEdges = max(maxEdges, v);
        return wall.size() - maxEdges;
    }
};