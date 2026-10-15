import java.util.*;

class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        boolean[][] visited = new boolean[n][n];
        PriorityQueue<Cell> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.time));
        pq.offer(new Cell(grid[0][0], 0, 0));
        visited[0][0] = true;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!pq.isEmpty()) {
            Cell cell = pq.poll();
            int t = cell.time;
            int r = cell.r;
            int c = cell.c;
            if (r == n-1 && c == n-1) {
                return t;
            }
            for (int[] d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nt = Math.max(t, grid[nr][nc]);
                    pq.offer(new Cell(nt, nr, nc));
                }
            }
        }
        return -1;
    }
    
    class Cell {
        int time, r, c;
        Cell(int time, int r, int c) {
            this.time = time;
            this.r = r;
            this.c = c;
        }
    }
}
