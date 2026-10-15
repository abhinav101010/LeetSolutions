class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxEnding = nums[0], maxBest = nums[0], minEnding = nums[0], minBest = nums[0];
        for (int x : nums) {
            maxEnding = max(x, maxEnding + x);
            maxBest = max(maxBest, maxEnding);
            minEnding = min(x, minEnding + x);
            minBest = min(minBest, minEnding);
            total += x;
        }
        if (maxBest < 0) return maxBest;
        return max(maxBest, total - minBest);
    }
};
