import java.util.*;

public class Solution {
    private long cross(int[] a, int[] b, int[] c) {
        return (long)(b[0] - a[0]) * (c[1] - b[1]) - (long)(b[1] - a[1]) * (c[0] - b[0]);
    }
    
    public boolean isConvex(int[][] points) {
        int n = points.length;
        if (n < 3) return false;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            long c = cross(points[i], points[(i + 1) % n], points[(i + 2) % n]);
            if (c != 0) {
                int sign = c > 0 ? 1 : -1;
                if (cur == 0) cur = sign;
                else if (cur != sign) return false;
            }
        }
        return true;
    }
}
