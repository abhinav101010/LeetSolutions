import java.util.*;

class Solution {
    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length;
        int n = grid[0].length();
        int sx = 0, sy = 0;
        int keyCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i].charAt(j);
                if (c == '@') {
                    sx = i; sy = j;
                }
                if (Character.isLowerCase(c)) {
                    keyCount++;
                }
            }
        }
        if (keyCount == 0) return 0;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        Queue<int[]> q = new ArrayDeque<>(); // x, y, mask, dist
        boolean[][][] visited = new boolean[m][n][1 << keyCount];
        q.offer(new int[]{sx, sy, 0, 0});
        visited[sx][sy][0] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], mask = cur[2], dist = cur[3];
            if (mask == (1 << keyCount) - 1) {
                return dist;
            }
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                char c = grid[nx].charAt(ny);
                if (c == '#') continue;
                int nmask = mask;
                if (Character.isLowerCase(c)) {
                    int bit = c - 'a';
                    nmask |= (1 << bit);
                } else if (Character.isUpperCase(c)) {
                    int bit = c - 'A';
                    if ((mask & (1 << bit)) == 0) continue;
                }
                if (!visited[nx][ny][nmask]) {
                    visited[nx][ny][nmask] = true;
                    q.offer(new int[]{nx, ny, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
}
