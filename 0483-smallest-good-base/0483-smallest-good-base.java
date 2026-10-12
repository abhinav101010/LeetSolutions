class Solution {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        int maxM = (int)(Math.log(num) / Math.log(2)) + 1;
        
        for (int m = maxM; m >= 2; m--) {
            long k = (long)Math.pow(num, 1.0 / m);
            if (k <= 1) continue;
            long total = (pow(k, m + 1) - 1) / (k - 1);
            if (total == num) {
                return String.valueOf(k);
            }
        }
        
        return String.valueOf(num - 1);
    }
    
    private long pow(long base, int exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }
}