#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        dfs(0, graph.size() - 1, graph, path, result);
        return result;
    }
private:
    void dfs(int u, int target, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        if (u == target) {
            result.push_back(path);
            return;
        }
        for (int v : graph[u]) {
            path.push_back(v);
            dfs(v, target, graph, path, result);
            path.pop_back();
        }
    }
};
