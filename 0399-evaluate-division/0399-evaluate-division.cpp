class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < (int)equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }
        
        vector<double> result;
        for (auto& q : queries) {
            result.push_back(bfs(q[0], q[1], graph));
        }
        return result;
    }
    
private:
    double bfs(const string& start, const string& end, 
               unordered_map<string, vector<pair<string, double>>>& graph) {
        if (!graph.count(start) || !graph.count(end)) return -1.0;
        if (start == end) return 1.0;
        
        unordered_set<string> visited = {start};
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        
        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();
            
            if (node == end) return val;
            
            for (auto& [nei, weight] : graph[node]) {
                if (!visited.count(nei)) {
                    visited.insert(nei);
                    q.push({nei, val * weight});
                }
            }
        }
        return -1.0;
    }
};