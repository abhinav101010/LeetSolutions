import java.util.*;
class Solution {
    public int maximumMinimumPath(int[][] A) {
        int m = A.length, n = A[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));
        pq.offer(new int[]{A[0][0], 0, 0});
        boolean[][] seen = new boolean[m][n];
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int score = cur[0], x = cur[1], y = cur[2];
            if (x == m - 1 && y == n - 1) return score;
            if (seen[x][y]) continue;
            seen[x][y] = true;
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny]) {
                    pq.offer(new int[]{Math.min(score, A[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }
}
