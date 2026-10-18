import java.util.*;

class Point { int x; }

class Solution {
    public int shortestDistance(List<Point> points) {
        int n = points.size();
        if (n < 2) return 0;
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.abs(points.get(i).x - points.get(j).x);
                if (d < best) best = d;
            }
        }
        return best == Integer.MAX_VALUE ? 0 : best;
    }
}
