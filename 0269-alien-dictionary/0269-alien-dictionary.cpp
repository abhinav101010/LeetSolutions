class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        for (auto &w : words) {
            for (char c : w) {
                indegree[c] = 0;
                graph[c] = unordered_set<char>();
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (graph[w1[j]].find(w2[j]) == graph[w1[j]].end()) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
            if (w1.size() > w2.size() && w1.find(w2) == 0) return "";
        }
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }
        string res;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            res += c;
            for (char nxt : graph[c]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
        }
        if (res.size() != indegree.size()) return "";
        return res;
    }
};