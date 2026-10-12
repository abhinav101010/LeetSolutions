import java.util.*;

class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] points = {p1, p2, p3, p4};
        int[] dists = new int[6];
        int idx = 0;
        
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                dists[idx++] = dx * dx + dy * dy;
            }
        }
        
        Arrays.sort(dists);
        return dists[0] > 0 && dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3] && 
               dists[4] == dists[5] && dists[4] == 2 * dists[0];
    }
}