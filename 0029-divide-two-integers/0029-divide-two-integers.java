class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        long dvd = dividend;
        long dvr = divisor;
        boolean negative = (dvd < 0) ^ (dvr < 0);

        if (dvd < 0) {
            dvd = -dvd;
        }
        if (dvr < 0) {
            dvr = -dvr;
        }

        long quotient = 0;
        while (dvd >= dvr) {
            long multiple = 1;
            long temp = dvr;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? (int) -quotient : (int) quotient;
    }
}
