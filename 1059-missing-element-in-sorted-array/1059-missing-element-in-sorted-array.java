class Solution {
    public int missingElement(int[] nums, int k) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - nums[i-1] > 1) {
                int diff = nums[i] - nums[i-1] - 1;
                if (k <= diff) return nums[i-1] + k;
                k -= diff;
            }
        }
        return nums[nums.length-1] + k;
    }
}
