#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (const auto &t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }
        vector<int> debt;
        for (const auto &p : balance) {
            if (p.second != 0) debt.push_back(p.second);
        }
        return dfs(0, debt);
    }
private:
    int dfs(int pos, vector<int> &debt) {
        while (pos < (int)debt.size() && debt[pos] == 0) ++pos;
        if (pos == (int)debt.size()) return 0;
        int res = INT_MAX;
        for (int i = pos + 1; i < (int)debt.size(); ++i) {
            if ((debt[i] > 0 && debt[pos] < 0) || (debt[i] < 0 && debt[pos] > 0)) {
                debt[i] += debt[pos];
                res = min(res, 1 + dfs(pos + 1, debt));
                debt[i] -= debt[pos];
                if (debt[pos] + debt[i] == 0) break;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
