import java.math.BigInteger;

public class Solution {
    private long combination(int n, int r) {
        if (r > n - r) r = n - r;
        long res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    
    public String kthSmallestPath(int[] destination, int k) {
        int rows = destination[0], cols = destination[1];
        StringBuilder sb = new StringBuilder();
        int v = rows, h = cols;
        for (int i = 0; i < rows + cols; ++i) {
            if (h == 0) {
                sb.append('V');
                --v;
                continue;
            }
            if (v == 0) {
                sb.append('H');
                --h;
                continue;
            }
            long comb = combination(v + h - 1, h - 1);
            if (k <= comb) {
                sb.append('H');
                --h;
            } else {
                sb.append('V');
                --v;
                k -= comb;
            }
        }
        return sb.toString();
    }
}
