class Solution {
    public int pivotIndex(int[] nums) {
        int rightSum = 0;
        for (int num : nums) rightSum += num;
        int leftSum = 0;
        for (int i = 0; i < nums.length; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum - nums[i] == rightSum) return i;
        }
        return -1;
    }
}