import java.util.*;
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        String S = Integer.toString(N);
        int L = S.length();
        int d = D.length;
        int ans = 0;
        // numbers with length < L
        for (int i = 1; i < L; i++) {
            ans += (int) Math.pow(d, i);
        }
        int i = 0;
        while (i < L) {
            char c = S.charAt(i);
            int numLess = 0;
            for (String digit : D) {
                if (digit.charAt(0) < c) {
                    numLess++;
                }
            }
            ans += numLess * (int) Math.pow(d, L - i - 1);
            if (DContains(D, c) == false) {
                break;
            }
            i++;
        }
        if (i == L) {
            ans++; // N itself is valid
        }
        return ans;
    }
    private boolean DContains(String[] D, char c) {
        for (String digit : D) {
            if (digit.charAt(0) == c) {
                return true;
            }
        }
        return false;
    }
}
