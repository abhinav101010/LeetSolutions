import java.util.*;

class Solution {
    public int numDistinctIslands2(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        Set<String> signatures = new HashSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    List<int[]> cells = new ArrayList<>();
                    dfs(grid, visited, i, j, cells);
                    String canonical = getCanonical(cells);
                    signatures.add(canonical);
                }
            }
        }
        return signatures.size();
    }
    
    private void dfs(int[][] grid, boolean[][] visited, int i, int j, List<int[]> cells) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        cells.add(new int[]{i, j});
        dfs(grid, visited, i+1, j, cells);
        dfs(grid, visited, i-1, j, cells);
        dfs(grid, visited, i, j+1, cells);
        dfs(grid, visited, i, j-1, cells);
    }
    
    private String getCanonical(List<int[]> cells) {
        String min = null;
        for (int rot = 0; rot < 4; rot++) {
            for (int reflect = 0; reflect < 2; reflect++) {
                List<int[]> transformed = transform(cells, rot, reflect == 1);
                String norm = normalize(transformed);
                if (min == null || norm.compareTo(min) < 0) {
                    min = norm;
                }
            }
        }
        return min;
    }
    
    private List<int[]> transform(List<int[]> cells, int rot, boolean reflect) {
        List<int[]> res = new ArrayList<>();
        for (int[] p : cells) {
            int x = p[0], y = p[1];
            int xr = x, yr = y;
            for (int r = 0; r < rot; r++) {
                int tmp = xr;
                xr = yr;
                yr = -tmp;
            }
            if (reflect) {
                xr = -xr;
            }
            res.add(new int[]{xr, yr});
        }
        return res;
    }
    
    private String normalize(List<int[]> points) {
        int minx = Integer.MAX_VALUE, miny = Integer.MAX_VALUE;
        for (int[] p : points) {
            if (p[0] < minx) minx = p[0];
            if (p[1] < miny) miny = p[1];
        }
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (int[] p : points) {
            if (!first) sb.append(":");
            sb.append(p[0] - minx).append(",").append(p[1] - miny);
            first = false;
        }
        return sb.toString();
    }
}
