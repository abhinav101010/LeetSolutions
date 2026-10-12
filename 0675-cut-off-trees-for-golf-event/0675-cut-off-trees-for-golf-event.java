import java.util.*;

class Solution {
    private int m, n;
    private int[][] forest;
    
    public int cutOffTree(List<List<Integer>> forestList) {
        m = forestList.size();
        n = forestList.get(0).size();
        forest = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) forest[i][j] = forestList.get(i).get(j);
        }
        List<int[]> trees = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.add(new int[]{forest[i][j], i, j});
            }
        }
        trees.sort((a,b) -> a[0] - b[0]);
        int ans = 0, sx = 0, sy = 0;
        for (int[] t : trees) {
            int d = bfs(sx, sy, t[1], t[2]);
            if (d == -1) return -1;
            ans += d;
            sx = t[1]; sy = t[2];
        }
        return ans;
    }
    
    private int bfs(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        q.offer(new int[]{sx, sy, 0});
        visited[sx][sy] = true;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int[] dir : dirs) {
                int nx = cur[0] + dir[0], ny = cur[1] + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && forest[nx][ny] != 0) {
                    if (nx == tx && ny == ty) return cur[2] + 1;
                    visited[nx][ny] = true;
                    q.offer(new int[]{nx, ny, cur[2] + 1});
                }
            }
        }
        return -1;
    }
}