class Solution {
    public int maxProductDifference(int[] nums) {
        java.util.Arrays.sort(nums);
        int n = nums.length;
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
}