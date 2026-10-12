class Solution {
    public int minStartValue(int[] nums) {
        int total = 0;
        int minSum = 0;

        for (int num : nums) {
            total += num;
            minSum = Math.min(minSum, total);
        }

        return 1 - minSum;
    }
}
