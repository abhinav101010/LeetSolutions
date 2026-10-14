import java.util.*;

class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        int m = maze.length, n = maze[0].length;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int[][] dist = new int[m][n];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(a[0], b[0]));
        int sx = start[0], sy = start[1];
        dist[sx][sy] = 0;
        pq.offer(new int[]{0, sx, sy});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0], x = cur[1], y = cur[2];
            if (d > dist[x][y]) continue;
            if (x == destination[0] && y == destination[1]) {
                return d;
            }
            for (int[] dir : dirs) {
                int nx = x, ny = y;
                int steps = 0;
                while (nx + dir[0] >= 0 && nx + dir[0] < m && ny + dir[1] >= 0 && ny + dir[1] < n && maze[nx + dir[0]][ny + dir[1]] == 0) {
                    nx += dir[0];
                    ny += dir[1];
                    steps++;
                }
                int nd = d + steps;
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.offer(new int[]{nd, nx, ny});
                }
            }
        }
        return -1;
    }
}
