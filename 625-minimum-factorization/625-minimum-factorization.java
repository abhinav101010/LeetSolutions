class Solution {
    public int smallestFactorization(int a) {
        if (a < 2) return a;
        int[] count = new int[10]; // count of digits 2-9
        for (int d = 9; d >= 2; d--) {
            while (a % d == 0) {
                a /= d;
                count[d]++;
            }
        }
        if (a > 1) return 0;
        // build smallest number: put smallest digits first (i.e., from 2 to 9)
        long res = 0;
        for (int d = 2; d <= 9; d++) {
            for (int i = 0; i < count[d]; i++) {
                res = res * 10 + d;
                if (res > Integer.MAX_VALUE) return 0;
            }
        }
        return (int) res;
    }
}
