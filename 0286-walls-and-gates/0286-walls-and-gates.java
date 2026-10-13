import java.util.*;

class Solution {
    public void wallsAndGates(int[][] rooms) {
        if (rooms.length == 0 || rooms[0].length == 0) return;
        int m = rooms.length, n = rooms[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.add(new int[]{i, j});
                }
            }
        }
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && rooms[nx][ny] == 2147483647) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
}