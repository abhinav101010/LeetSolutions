class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        vector<unordered_map<long long, int>> dp(n);
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];
                int count = dp[j][diff];
                result += count;
                dp[i][diff] += count + 1;
            }
        }
        
        return result;
    }
};