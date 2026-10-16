import java.util.*;
class Solution {
    public double minAreaFreeRect(int[][] points) {
        int n = points.length;
        Map<String, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                long cx2 = (long)x1 + x2;
                long cy2 = (long)y1 + y2;
                long dx = x1 - x2;
                long dy = y1 - y2;
                long dist2 = dx*dx + dy*dy;
                String key = cx2 + "," + cy2 + "," + dist2;
                map.computeIfAbsent(key, k -> new ArrayList<>()).add(new int[]{i, j});
            }
        }
        double ans = Double.POSITIVE_INFINITY;
        for (List<int[]> pairs : map.values()) {
            int m = pairs.size();
            if (m < 2) continue;
            for (int a = 0; a < m; a++) {
                int i1 = pairs.get(a)[0];
                int i2 = pairs.get(a)[1];
                int x1 = points[i1][0], y1 = points[i1][1];
                int x3 = points[i2][0], y3 = points[i2][1];
                for (int b = a+1; b < m; b++) {
                    int j1 = pairs.get(b)[0];
                    int j2 = pairs.get(b)[1];
                    int x2 = points[j1][0], y2 = points[j1][1];
                    int x4 = points[j2][0], y4 = points[j2][1];
                    double area = Math.abs((x1 - x3)*(y2 - y4) - (y1 - y3)*(x2 - x4)) / 2.0;
                    if (area > 0) {
                        ans = Math.min(ans, area);
                    }
                }
            }
        }
        return ans == Double.POSITIVE_INFINITY ? 0 : ans;
    }
}
