import java.util.*;

public class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int total = 0;
        int maxDist = -1;
        for (int[] nut : nuts) {
            int d = Math.abs(tree[0] - nut[0]) + Math.abs(tree[1] - nut[1]);
            total += 2 * d;
            int d2 = Math.abs(squirrel[0] - nut[0]) + Math.abs(squirrel[1] - nut[1]);
            maxDist = Math.max(maxDist, d - d2);
        }
        return total - maxDist;
    }
}
