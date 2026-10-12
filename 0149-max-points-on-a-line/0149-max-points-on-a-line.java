import java.util.*;

class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) return n;
        
        int maxPoints = 0;
        
        for (int i = 0; i < n; i++) {
            Map<String, Integer> slopes = new HashMap<>();
            int same = 1;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    same++;
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    String key = dx + "," + dy;
                    slopes.put(key, slopes.getOrDefault(key, 0) + 1);
                }
            }
            
            int currentMax = same;
            for (int count : slopes.values()) {
                currentMax = Math.max(currentMax, count + same);
            }
            maxPoints = Math.max(maxPoints, currentMax);
        }
        
        return maxPoints;
    }
    
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}