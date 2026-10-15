class Solution {
    public int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 == 1) {
                    count++;
                }
                int j = n / i;
                if (j != i && (j % 2 == 1)) {
                    count++;
                }
            }
        }
        return count;
    }
}
