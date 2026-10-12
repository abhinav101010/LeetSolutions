class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            int dest = pre[0];
            int src = pre[1];
            graph[src].push_back(dest);
            indegree[dest]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int nei : graph[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        return count == numCourses;
    }
};