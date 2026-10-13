import java.util.*;

class Solution {
    public int shortestDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        int[][] reach = new int[m][n];
        int buildings = 0;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    buildings++;
                    Queue<int[]> q = new LinkedList<>();
                    q.offer(new int[]{i, j, 0});
                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        int x = cur[0], y = cur[1], d = cur[2];
                        for (int[] dir : dirs) {
                            int nx = x + dir[0], ny = y + dir[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && reach[nx][ny] == buildings - 1) {
                                dist[nx][ny] += d + 1;
                                reach[nx][ny] = buildings;
                                q.offer(new int[]{nx, ny, d + 1});
                            }
                        }
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reach[i][j] == buildings) {
                    res = Math.min(res, dist[i][j]);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}