class Solution {
    public int[] separateDigits(int[] nums) {
        int totalDigits = 0;
        for (int num : nums) {
            int temp = num;
            while (temp > 0) {
                totalDigits++;
                temp /= 10;
            }
        }
        int[] ans = new int[totalDigits];
        int idx = 0;
        for (int num : nums) {
            int[] digits = new int[10];
            int d = 0;
            while (num > 0) {
                digits[d++] = num % 10;
                num /= 10;
            }
            for (int i = d - 1; i >= 0; i--) {
                ans[idx++] = digits[i];
            }
        }
        return ans;
    }
}