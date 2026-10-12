import java.util.*;

class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        Set<String> points = new HashSet<>();
        long area = 0;
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
        
        for (int[] r : rectangles) {
            minX = Math.min(minX, r[0]);
            minY = Math.min(minY, r[1]);
            maxX = Math.max(maxX, r[2]);
            maxY = Math.max(maxY, r[3]);
            area += (long)(r[2] - r[0]) * (r[3] - r[1]);
            
            String[] corners = {r[0] + "," + r[1], r[0] + "," + r[3], r[2] + "," + r[1], r[2] + "," + r[3]};
            for (String p : corners) {
                if (points.contains(p)) points.remove(p);
                else points.add(p);
            }
        }
        
        if (points.size() != 4) return false;
        
        String[] expected = {minX + "," + minY, minX + "," + maxY, maxX + "," + minY, maxX + "," + maxY};
        if (!points.containsAll(Arrays.asList(expected))) return false;
        
        return area == (long)(maxX - minX) * (maxY - minY);
    }
}