import java.util.Arrays;

class Solution {
    public int gcdSum(int[] nums) {
        int n = nums.length;
        int[] prefixGcd = new int[n];
        int mxi = 0;
        for (int i = 0; i < n; i++) {
            mxi = Math.max(mxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], mxi);
        }
        Arrays.sort(prefixGcd);
        int ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}