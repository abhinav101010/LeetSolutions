class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] newNums = new int[2 * n];

        for (int i = 0; i < n; i++) {
            newNums[2 * i] = nums[i];
            newNums[2 * i + 1] = nums[n + i];
        }

        return newNums;
    }
}