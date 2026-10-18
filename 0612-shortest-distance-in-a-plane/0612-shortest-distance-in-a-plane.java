import java.util.*;

class Point {
    int x;
    int y;
    Point(int x, int y) { this.x = x; this.y = y; }
}

class Solution {
    public double shortestDistance(List<Point> points) {
        int n = points.size();
        if (n < 2) return 0.0;
        long minSq = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long dx = (long) points.get(i).x - (long) points.get(j).x;
                long dy = (long) points.get(i).y - (long) points.get(j).y;
                long sq = dx * dx + dy * dy;
                if (sq < minSq) minSq = sq;
            }
        }
        double d = Math.sqrt((double) minSq);
        return Math.round(d * 100.0) / 100.0;
    }
}
