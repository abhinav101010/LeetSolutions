#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
    map<string,int> memo;
    int dp(vector<vector<int>>& w, vector<vector<int>>& b, int i, int mask) {
        if (i == w.size()) return 0;
        string key = to_string(i) + "," + to_string(mask);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        int best = INT_MAX;
        for (int j = 0; j < b.size(); j++) {
            if (mask >> j & 1) continue;
            int d = abs(w[i][0]-b[j][0]) + abs(w[i][1]-b[j][1]);
            best = min(best, d + dp(w,b,i+1,mask|(1<<j)));
        }
        memo[key] = best;
        return best;
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memo.clear();
        return dp(workers, bikes, 0, 0);
    }
};
