import java.util.List;
import java.util.Arrays;

class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, List<int[]> nuts) {
        int total = 0;
        int maxSave = 0;
        for (int[] nut : nuts) {
            int dTree = Math.abs(tree[0] - nut[0]) + Math.abs(tree[1] - nut[1]);
            total += 2 * dTree;
            int dSquirrel = Math.abs(squirrel[0] - nut[0]) + Math.abs(squirrel[1] - nut[1]);
            int save = dTree - dSquirrel;
            if (save > maxSave) {
                maxSave = save;
            }
        }
        return total - maxSave;
    }
}
