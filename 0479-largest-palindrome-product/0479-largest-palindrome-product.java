class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = (int)Math.pow(10, n) - 1;
        int lower = (int)Math.pow(10, n - 1);
        for (int i = upper; i >= lower; i--) {
            String s = String.valueOf(i);
            String rev = new StringBuilder(s).reverse().toString();
            long pal = Long.parseLong(s + rev);
            for (int j = upper; j >= Math.sqrt(pal); j--) {
                if (pal % j == 0 && pal / j >= lower && pal / j <= upper) {
                    return (int)(pal % 1337);
                }
            }
        }
        return 0;
    }
}