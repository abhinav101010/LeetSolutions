import java.util.*;

class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length, n = maze[0].length;
        boolean[][] visited = new boolean[m][n];
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            if (x == destination[0] && y == destination[1]) {
                return true;
            }
            for (int[] d : dirs) {
                int nx = x, ny = y;
                // roll
                while (nx + d[0] >= 0 && nx + d[0] < m && ny + d[1] >= 0 && ny + d[1] < n && maze[nx + d[0]][ny + d[1]] == 0) {
                    nx += d[0];
                    ny += d[1];
                }
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return false;
    }
}
