class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int total = 0, maxEnding = nums[0], maxBest = nums[0], minEnding = nums[0], minBest = nums[0];
        for (int x : nums) {
            maxEnding = Math.max(x, maxEnding + x);
            maxBest = Math.max(maxBest, maxEnding);
            minEnding = Math.min(x, minEnding + x);
            minBest = Math.min(minBest, minEnding);
            total += x;
        }
        if (maxBest < 0) {
            return maxBest;
        }
        return Math.max(maxBest, total - minBest);
    }
}
