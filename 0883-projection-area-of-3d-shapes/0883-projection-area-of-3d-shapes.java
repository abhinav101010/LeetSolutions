class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length;
        int top = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) top++;
            }
        }
        int front = 0;
        for (int i = 0; i < n; i++) {
            int maxRow = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > maxRow) maxRow = grid[i][j];
            }
            front += maxRow;
        }
        int side = 0;
        for (int j = 0; j < n; j++) {
            int maxCol = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] > maxCol) maxCol = grid[i][j];
            }
            side += maxCol;
        }
        return top + front + side;
    }
}
