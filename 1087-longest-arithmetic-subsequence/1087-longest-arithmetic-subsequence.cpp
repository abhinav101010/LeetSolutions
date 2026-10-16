#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int d = nums[j] - nums[i];
                dp[j][d] = dp[i].count(d) ? dp[i][d] + 1 : 2;
                ans = max(ans, dp[j][d]);
            }
        }
        return ans;
    }
};
