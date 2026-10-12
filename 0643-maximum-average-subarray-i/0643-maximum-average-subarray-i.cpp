class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long window = 0;
        for (int i = 0; i < k; i++) {
            window += nums[i];
        }
        long long maxSum = window;
        for (int i = k; i < (int)nums.size(); i++) {
            window += nums[i];
            window -= nums[i - k];
            if (window > maxSum) {
                maxSum = window;
            }
        }
        return (double)maxSum / (double)k;
    }
};
