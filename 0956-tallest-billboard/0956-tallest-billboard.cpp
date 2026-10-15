#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int r : rods) {
            unordered_map<int, int> newdp(dp);
            for (auto& kv : dp) {
                int diff = kv.first;
                int h = kv.second;
                // add to positive side
                int ndiff = diff + r;
                int nh = h + r;
                if (nh > newdp[ndiff]) {
                    newdp[ndiff] = nh;
                }
                // add to negative side
                ndiff = diff - r;
                nh = h;
                if (nh > newdp[ndiff]) {
                    newdp[ndiff] = nh;
                }
            }
            dp = move(newdp);
        }
        return dp[0];
    }
};
