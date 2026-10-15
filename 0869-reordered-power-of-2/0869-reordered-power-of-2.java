class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] cntN = digitCount(n);
        for (int i = 0; i < 31; i++) {
            int p = 1 << i;
            if (matches(digitCount(p), cntN)) {
                return true;
            }
        }
        return false;
    }
    private int[] digitCount(int x) {
        int[] cnt = new int[10];
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }
    private boolean matches(int[] a, int[] b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
}
