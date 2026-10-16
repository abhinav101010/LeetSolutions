import java.util.*;
class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int[][] cells = new int[rows * cols][2];
        int idx = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                cells[idx][0] = r; cells[idx][1] = c; idx++;
            }
        Arrays.sort(cells, (a, b) -> {
            int da = Math.abs(a[0]-rCenter) + Math.abs(a[1]-cCenter);
            int db = Math.abs(b[0]-rCenter) + Math.abs(b[1]-cCenter);
            return Integer.compare(da, db);
        });
        return cells;
    }
}
