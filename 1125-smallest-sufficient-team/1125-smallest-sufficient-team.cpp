#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        unordered_map<string, int> skill_to_idx;
        for (int i = 0; i < m; i++) {
            skill_to_idx[req_skills[i]] = i;
        }
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++) {
            for (string& s : people[i]) {
                p[i] |= 1 << skill_to_idx[s];
            }
        }
        int total = 1 << m;
        vector<int> f(total, n + 1);
        vector<int> g(total, 0);
        vector<int> h(total, 0);
        f[0] = 0;
        for (int i = 0; i < total; i++) {
            if (f[i] == n + 1) continue;
            for (int j = 0; j < n; j++) {
                int nxt = i | p[j];
                if (f[i] + 1 < f[nxt]) {
                    f[nxt] = f[i] + 1;
                    g[nxt] = j;
                    h[nxt] = i;
                }
            }
        }
        vector<int> ans;
        int i = total - 1;
        while (i) {
            ans.push_back(g[i]);
            i = h[i];
        }
        return ans;
    }
};