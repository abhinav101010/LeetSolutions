import java.util.*;

class Solution {
    public boolean isReflected(int[][] points) {
        if (points.length == 0) return true;
        int minX = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        Set<String> set = new HashSet<>();
        for (int[] p : points) {
            minX = Math.min(minX, p[0]);
            maxX = Math.max(maxX, p[0]);
            set.add(p[0] + "," + p[1]);
        }
        int sumX = minX + maxX;
        for (int[] p : points) {
            if (!set.contains((sumX - p[0]) + "," + p[1])) {
                return false;
            }
        }
        return true;
    }
}