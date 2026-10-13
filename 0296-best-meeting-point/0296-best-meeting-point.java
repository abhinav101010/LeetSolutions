import java.util.*;

class Solution {
    public int minTotalDistance(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.add(i);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    cols.add(j);
                }
            }
        }
        return getDistance(rows) + getDistance(cols);
    }
    
    private int getDistance(List<Integer> points) {
        int res = 0;
        int l = 0, r = points.size() - 1;
        while (l < r) {
            res += points.get(r--) - points.get(l++);
        }
        return res;
    }
}