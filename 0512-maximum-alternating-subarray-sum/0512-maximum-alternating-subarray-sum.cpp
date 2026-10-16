#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long dp0 = 0, dp1 = 0;
        long long ans = 0;
        for (int x : nums) {
            long long ndp0 = max(dp0, dp1 + x);
            long long ndp1 = max(dp1, dp0 - x);
            dp0 = ndp0; dp1 = ndp1;
            ans = max({ans, dp0, dp1});
        }
        return ans;
    }
};
