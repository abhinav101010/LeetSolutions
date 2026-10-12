class Solution {
    public int missingInteger(int[] nums) {
        int total = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }
        boolean[] seen = new boolean[51];
        for (int num : nums) {
            if (num <= 50) seen[num] = true;
        }
        while (seen[total]) {
            total++;
        }
        return total;
    }
}