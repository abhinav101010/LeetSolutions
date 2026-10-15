import java.util.*;
class Solution {
    public int shortestBridge(int[][] A) {
        int n = A.length;
        Queue<int[]> q = new LinkedList<>();
        boolean found = false;
        // dfs to mark first island
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, n, q);
                    found = true;
                }
            }
        }
        int steps = 0;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] cell = q.poll();
                int r = cell[0], c = cell[1];
                for (int[] dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (A[nr][nc] == 1) {
                            return steps;
                        }
                        if (A[nr][nc] == 0) {
                            A[nr][nc] = 2; // visited
                            q.offer(new int[]{nr, nc});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    private void dfs(int[][] A, int r, int c, int n, Queue<int[]> q) {
        if (r < 0 || r >= n || c < 0 || c >= n || A[r][c] != 1) return;
        A[r][c] = 2;
        q.offer(new int[]{r, c});
        dfs(A, r+1, c, n, q);
        dfs(A, r-1, c, n, q);
        dfs(A, r, c+1, n, q);
        dfs(A, r, c-1, n, q);
    }
}
