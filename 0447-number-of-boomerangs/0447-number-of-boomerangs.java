import java.util.*;

class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int result = 0;
        for (int i = 0; i < points.length; i++) {
            Map<Integer, Integer> distCount = new HashMap<>();
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx * dx + dy * dy;
                distCount.put(dist, distCount.getOrDefault(dist, 0) + 1);
            }
            
            for (int count : distCount.values()) {
                result += count * (count - 1);
            }
        }
        return result;
    }
}