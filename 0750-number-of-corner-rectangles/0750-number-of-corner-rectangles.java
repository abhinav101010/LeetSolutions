class Solution {
    public int numberOfCornerRectangles(int[][] grid) {
        int R = grid.length;
        int C = grid[0].length;
        long ans = 0;
        for (int c1 = 0; c1 < C; c1++) {
            for (int c2 = c1+1; c2 < C; c2++) {
                int cnt = 0;
                for (int r = 0; r < R; r++) {
                    if (grid[r][c1] == 1 && grid[r][c2] == 1) {
                        cnt++;
                    }
                }
                ans += (long)cnt * (cnt - 1) / 2;
            }
        }
        return (int)ans;
    }
}
