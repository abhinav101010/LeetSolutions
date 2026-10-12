import java.util.*;

class Solution {
    public int[] constructArray(int n, int k) {
        int[] res = new int[n];
        int idx = 0;
        for (int i = 1; i <= n - k; i++) res[idx++] = i;
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) res[idx++] = n - k + i / 2;
            else res[idx++] = n - i / 2;
        }
        return res;
    }
}