#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        if (n == 1) {
            string sb;
            for (int i = 0; i < k; i++) sb += ('0' + i);
            return sb;
        }
        unordered_set<string> visited;
        vector<int> ans;
        string start(n-1, '0');
        dfs(start, visited, ans, k);
        string res = start;
        for (int i = ans.size() - 1; i >= 0; i--) {
            res += ('0' + ans[i]);
        }
        return res;
    }
    
private:
    void dfs(string node, unordered_set<string>& visited, vector<int>& ans, int k) {
        for (int x = 0; x < k; x++) {
            char c = '0' + x;
            string edge = node + string(1, c);
            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                dfs(edge.substr(1), visited, ans, k);
                ans.push_back(x);
            }
        }
    }
};
