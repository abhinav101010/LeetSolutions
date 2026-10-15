class Solution {
    public int superpalindromesInRange(String left, String right) {
        long L = Long.parseLong(left);
        long R = Long.parseLong(right);
        int count = 0;
        // generate palindromes
        for (int k = 1; k < 10000; k++) {
            String s = Integer.toString(k);
            // odd length
            StringBuilder odd = new StringBuilder(s);
            odd.append(new StringBuilder(s).reverse().substring(1));
            long p_odd = Long.parseLong(odd.toString());
            long square = p_odd * p_odd;
            if (square > R) {
                // we cannot break because even may still be smaller? but we continue
            } else {
                if (square >= L && isPalindrome(square)) {
                    count++;
                }
            }
            // even length
            StringBuilder even = new StringBuilder(s);
            even.append(new StringBuilder(s).reverse());
            long p_even = Long.parseLong(even.toString());
            square = p_even * p_even;
            if (square > R) {
                // continue
            } else {
                if (square >= L && isPalindrome(square)) {
                    count++;
                }
            }
        }
        return count;
    }
    private boolean isPalindrome(long x) {
        String s = Long.toString(x);
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
}
