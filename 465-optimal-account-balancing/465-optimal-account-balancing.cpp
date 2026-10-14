#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> bal;
        for (auto& t : transactions) {
            int x = t[0], y = t[1], z = t[2];
            bal[x] -= z;
            bal[y] += z;
        }
        vector<long> debts;
        for (auto& p : bal) {
            if (p.second != 0) debts.push_back(p.second);
        }
        int n = debts.size();
        return dfs(debts, 0);
    }
    
private:
    int dfs(vector<long>& debts, int start) {
        int n = debts.size();
        while (start < n && debts[start] == 0) {
            start++;
        }
        if (start == n) return 0;
        int res = INT_MAX;
        unordered_set<long> seen;
        for (int i = start + 1; i < n; i++) {
            long di = debts[i], ds = debts[start];
            if (di * ds < 0 && !seen.count(di)) {
                seen.insert(di);
                debts[i] = di + ds;
                res = min(res, 1 + dfs(debts, start + 1));
                debts[i] = di;
            }
        }
        return res;
    }
};
