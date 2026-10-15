import java.util.*;
class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int[] size = new int[n * n + 1];
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int s = dfs(grid, i, j, id, n);
                    size[id] = s;
                    id++;
                }
            }
        }
        int ans = 0;
        for (int v : size) ans = Math.max(ans, v);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> seen = new HashSet<>();
                    int sum = 0;
                    for (int[] dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            int root = grid[ni][nj];
                            if (!seen.contains(root)) {
                                seen.add(root);
                                sum += size[root];
                            }
                        }
                    }
                    ans = Math.max(ans, sum + 1);
                }
            }
        }
        return ans;
    }
    private int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    private int dfs(int[][] grid, int i, int j, int id, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        int sum = 1;
        for (int[] dir : dirs) {
            sum += dfs(grid, i + dir[0], j + dir[1], id, n);
        }
        return sum;
    }
}
