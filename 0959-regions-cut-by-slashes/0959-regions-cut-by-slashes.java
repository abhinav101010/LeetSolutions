class Solution {
    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int N = n * 3;
        int[][] g = new int[N][N];
        for (int r = 0; r < n; r++) {
            String row = grid[r];
            for (int c = 0; c < n; c++) {
                if (row.charAt(c) == '/') {
                    g[r*3][c*3+2] = 1;
                    g[r*3+1][c*3+1] = 1;
                    g[r*3+2][c*3] = 1;
                } else if (row.charAt(c) == '\\') {
                    g[r*3][c*3] = 1;
                    g[r*3+1][c*3+1] = 1;
                    g[r*3+2][c*3+2] = 1;
                }
                // else space: keep 0
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][j] == 0) {
                    ans++;
                    dfs(g, i, j, N);
                }
            }
        }
        return ans;
    }
    private void dfs(int[][] g, int x, int y, int N) {
        if (x < 0 || x >= N || y < 0 || y >= N || g[x][y] != 0) return;
        g[x][y] = 1;
        dfs(g, x+1, y, N);
        dfs(g, x-1, y, N);
        dfs(g, x, y+1, N);
        dfs(g, x, y-1, N);
    }
}
