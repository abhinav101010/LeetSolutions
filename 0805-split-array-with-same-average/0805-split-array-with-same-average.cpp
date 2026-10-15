#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int v : nums) total += v;
        // dp[k] = set of possible sums using k elements
        vector<unordered_set<int>> dp(n/2 + 1);
        dp[0].insert(0);
        for (int num : nums) {
            for (int k = n/2; k >= 1; k--) {
                for (int sum : dp[k-1]) {
                    dp[k].insert(sum + num);
                }
            }
        }
        for (int k = 1; k <= n/2; k++) {
            if ((total * k) % n == 0) {
                int target = (total * k) / n;
                if (dp[k].find(target) != dp[k].end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
