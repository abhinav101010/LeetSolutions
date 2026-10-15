class Solution {
    public int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n == 3) return 3;
        if (8 <= n && n <= 11) return 11;
        // generate odd length palindromes
        for (int length = 1; length <= 5; length++) {
            int start = (int) Math.pow(10, length - 1);
            int end = (int) Math.pow(10, length);
            for (int x = start; x < end; x++) {
                String s = Integer.toString(x);
                StringBuilder sb = new StringBuilder(s);
                sb.append(new StringBuilder(s).reverse().substring(1));
                int pal = Integer.parseInt(sb.toString());
                if (pal >= n && isPrime(pal)) {
                    return pal;
                }
            }
        }
        return -1;
    }
    private boolean isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }
}
