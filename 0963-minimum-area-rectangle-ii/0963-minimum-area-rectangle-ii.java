import java.util.*;
class Solution {
    public double minAreaFreeRect(int[][] points) {
        int n = points.length;
        Map<String, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int mx = x1 + x2;
                int my = y1 + y2;
                int dx = x1 - x2;
                int dy = y1 - y2;
                int dist2 = dx*dx + dy*dy;
                String key = mx + "," + my + "," + dist2;
                map.computeIfAbsent(key, k -> new ArrayList<>()).add(new int[]{dx, dy});
            }
        }
        double ans = Double.MAX_VALUE;
        for (List<int[]> vecs : map.values()) {
            int m = vecs.size();
            if (m < 2) continue;
            for (int i = 0; i < m; i++) {
                int x1 = vecs.get(i)[0];
                int y1 = vecs.get(i)[1];
                for (int j = i+1; j < m; j++) {
                    int x2 = vecs.get(j)[0];
                    int y2 = vecs.get(j)[1];
                    double area = Math.abs((double)(x1*y2 - y1*x2)) / 2.0;
                    if (area > 0 && area < ans) {
                        ans = area;
                    }
                }
            }
        }
        return ans == Double.MAX_VALUE ? 0 : ans;
    }
}
