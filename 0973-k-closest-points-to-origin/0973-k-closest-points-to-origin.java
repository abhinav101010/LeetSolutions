import java.util.*;
import java.awt.Point;
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        Arrays.sort(points, (a, b) -> {
            long da = (long)a[0]*a[0] + (long)a[1]*a[1];
            long db = (long)b[0]*b[0] + (long)b[1]*b[1];
            return Long.compare(da, db);
        });
        return Arrays.copyOf(points, k);
    }
}
