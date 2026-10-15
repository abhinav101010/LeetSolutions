import java.util.*;
class Solution {
    public int minAreaRect(int[][] points) {
        Set<Long> set = new HashSet<>();
        for (int[] p : points) {
            long key = ((long) p[0] << 32) | (p[1] & 0xffffffffL);
            set.add(key);
        }
        int ans = Integer.MAX_VALUE;
        int n = points.length;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                long key1 = ((long) x1 << 32) | (y2 & 0xffffffffL);
                long key2 = ((long) x2 << 32) | (y1 & 0xffffffffL);
                if (set.contains(key1) && set.contains(key2)) {
                    int area = Math.abs(x1 - x2) * Math.abs(y1 - y2);
                    if (area < ans) ans = area;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}
