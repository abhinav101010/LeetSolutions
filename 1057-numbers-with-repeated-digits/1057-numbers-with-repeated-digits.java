import java.util.*;
class Solution {
    public int numDupDigitsAtMostN(int n) {
        String s = String.valueOf(n);
        int length = s.length();
        int ans = 0;
        for (int i = 1; i < length; i++) {
            ans += 9 * permutation(9, i-1);
        }
        Set<Integer> used = new HashSet<>();
        for (int i = 0; i < length; i++) {
            int c = s.charAt(i) - '0';
            for (int d = 0; d < c; d++) {
                if (d == 0 && i == 0) continue;
                if (used.contains(d)) continue;
                ans += permutation(9 - i, length - 1 - i);
            }
            if (used.contains(c)) break;
            used.add(c);
        }
        if (used.size() == length) ans++;
        return n - ans;
    }
    private int permutation(int n, int k) {
        if (k > n || k < 0) return 0;
        int res = 1;
        for (int i = 0; i < k; i++) res *= (n - i);
        return res;
    }
}
