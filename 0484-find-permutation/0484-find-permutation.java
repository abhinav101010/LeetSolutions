import java.util.*;

class Solution {
    public int[] findPermutation(String s) {
        int n = s.length() + 1;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = i + 1;
        }
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == 'I') {
                i++;
                continue;
            }
            int j = i;
            while (j < s.length() && s.charAt(j) == 'D') {
                j++;
            }
            // reverse res[i..j]
            int l = i, r = j;
            while (l < r) {
                int tmp = res[l];
                res[l] = res[r];
                res[r] = tmp;
                l++;
                r--;
            }
            i = j;
        }
        return res;
    }
}
