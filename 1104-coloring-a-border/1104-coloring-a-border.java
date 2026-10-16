import java.util.*;
class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        int m = grid.length, n = grid[0].length;
        int orig = grid[r0][c0];
        if (orig == color) return grid;
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r0, c0});
        boolean[][] comp = new boolean[m][n];
        comp[r0][c0] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0], c = cur[1];
            for (int[] d : new int[][]{{1,0},{-1,0},{0,1},{0,-1}}) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == orig && !comp[nr][nc]) {
                    comp[nr][nc] = true;
                    q.add(new int[]{nr, nc});
                }
            }
        }
        List<int[]> border = new ArrayList<>();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!comp[r][c]) continue;
                boolean isBorder = (r == 0 || r == m-1 || c == 0 || c == n-1);
                if (!isBorder) {
                    for (int[] d : new int[][]{{1,0},{-1,0},{0,1},{0,-1}}) {
                        if (grid[r+d[0]][c+d[1]] != orig) { isBorder = true; break; }
                    }
                }
                if (isBorder) border.add(new int[]{r, c});
            }
        }
        for (int[] b : border) grid[b[0]][b[1]] = color;
        return grid;
    }
}
