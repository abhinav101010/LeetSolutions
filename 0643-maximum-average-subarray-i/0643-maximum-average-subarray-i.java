class Solution {
    public double findMaxAverage(int[] nums, int k) {
        long window = 0;
        for (int i = 0; i < k; i++) {
            window += nums[i];
        }
        long maxSum = window;
        for (int i = k; i < nums.length; i++) {
            window += nums[i];
            window -= nums[i - k];
            if (window > maxSum) {
                maxSum = window;
            }
        }
        return (double) maxSum / (double) k;
    }
}
