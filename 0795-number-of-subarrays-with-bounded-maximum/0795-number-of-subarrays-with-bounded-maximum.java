class Solution {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
    private int count(int[] nums, int bound) {
        int res = 0;
        int cur = 0;
        for (int v : nums) {
            if (v <= bound) {
                cur++;
            } else {
                cur = 0;
            }
            res += cur;
        }
        return res;
    }
}
