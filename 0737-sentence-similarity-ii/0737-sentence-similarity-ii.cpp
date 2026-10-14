#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<string, string> parent;
    string find(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void union_(string a, string b) {
        string ra = find(a);
        string rb = find(b);
        if (ra != rb) {
            parent[rb] = ra;
        }
    }
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        for (auto& p : pairs) {
            union_(p[0], p[1]);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) continue;
            if (find(words1[i]) != find(words2[i])) {
                return false;
            }
        }
        return true;
    }
};
