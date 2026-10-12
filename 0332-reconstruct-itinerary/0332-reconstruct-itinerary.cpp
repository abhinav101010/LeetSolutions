class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }
    
private:
    void dfs(const string& airport, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& route) {
        auto it = graph.find(airport);
        while (it != graph.end() && !it->second.empty()) {
            string next = it->second.top();
            it->second.pop();
            dfs(next, graph, route);
        }
        route.push_back(airport);
    }
};