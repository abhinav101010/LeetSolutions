class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        
        for (int num : nums) {
            unordered_map<int, int> nextDp;
            for (auto& [sum, count] : dp) {
                nextDp[sum + num] += count;
                nextDp[sum - num] += count;
            }
            dp = move(nextDp);
        }
        
        return dp[target];
    }
};