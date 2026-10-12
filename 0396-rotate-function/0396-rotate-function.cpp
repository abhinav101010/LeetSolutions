class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            curr += (long long)i * nums[i];
        }
        
        long long maxVal = curr;
        for (int i = n - 1; i > 0; i--) {
            curr = curr + total - (long long)n * nums[i];
            maxVal = max(maxVal, curr);
        }
        
        return (int)maxVal;
    }
};