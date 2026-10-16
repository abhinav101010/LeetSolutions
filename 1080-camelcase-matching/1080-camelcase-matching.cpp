#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& q : queries) res.push_back(match(q, pattern));
        return res;
    }
    bool match(string& q, string& p) {
        int i = 0;
        for (char c : q) {
            if (i < p.size() && c == p[i]) i++;
            else if (isupper(c)) return false;
        }
        return i == p.size();
    }
};
