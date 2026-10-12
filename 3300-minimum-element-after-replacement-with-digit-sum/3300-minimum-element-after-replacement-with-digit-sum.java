class Solution {
    public int minElement(int[] nums) {
        int ans = Integer.MAX_VALUE;
        for (int num : nums) {
            int sum = 0;
            int n = num;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            ans = Math.min(ans, sum);
        }
        return ans;
    }
}