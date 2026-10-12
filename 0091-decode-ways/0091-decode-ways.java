class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int prev2 = 1;
        int prev1 = s.charAt(0) == '0' ? 0 : 1;

        for (int i = 2; i <= n; i++) {
            int curr = 0;
            char one = s.charAt(i - 1);
            char ten = s.charAt(i - 2);

            if (one != '0') {
                curr += prev1;
            }
            if (ten == '1' || (ten == '2' && one <= '6')) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}
