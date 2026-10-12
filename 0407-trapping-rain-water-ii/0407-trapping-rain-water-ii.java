import java.util.*;

class Solution {
    public int trapRainWater(int[][] heightMap) {
        if (heightMap == null || heightMap.length == 0 || heightMap[0].length == 0) return 0;
        
        int m = heightMap.length, n = heightMap[0].length;
        if (m < 3 || n < 3) return 0;
        
        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        for (int i = 0; i < m; i++) {
            pq.offer(new int[]{heightMap[i][0], i, 0});
            pq.offer(new int[]{heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            pq.offer(new int[]{heightMap[0][j], 0, j});
            pq.offer(new int[]{heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }
        
        int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int water = 0;
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int h = curr[0], x = curr[1], y = curr[2];
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    water += Math.max(0, h - heightMap[nx][ny]);
                    pq.offer(new int[]{Math.max(h, heightMap[nx][ny]), nx, ny});
                }
            }
        }
        
        return water;
    }
}