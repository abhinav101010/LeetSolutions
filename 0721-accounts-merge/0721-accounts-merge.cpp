#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void union_(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra != rb) {
            parent[rb] = ra;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        for (int i = 0; i < n; i++) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToName[email] = name;
                if (!emailToId.count(email)) {
                    emailToId[email] = i;
                } else {
                    union_(i, emailToId[email]);
                }
            }
        }
        unordered_map<int, vector<string>> groups;
        for (auto& kv : emailToId) {
            string email = kv.first;
            int idx = kv.second;
            int root = find(idx);
            groups[root].push_back(email);
        }
        vector<vector<string>> res;
        for (auto& kv : groups) {
            vector<string>& emails = kv.second;
            sort(emails.begin(), emails.end());
            string name = emailToName[emails[0]];
            vector<string> entry;
            entry.push_back(name);
            entry.insert(entry.end(), emails.begin(), emails.end());
            res.push_back(entry);
        }
        return res;
    }
};
