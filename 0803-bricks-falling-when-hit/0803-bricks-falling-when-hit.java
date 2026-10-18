import java.util.*;

class Solution {
    int[] parent;
    int[] sz;
    int n;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) { int t = a; a = b; b = t; }
        parent[b] = a;
        sz[a] += sz[b];
    }

    int idx(int r, int c) { return r * n + c; }

    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length;
        n = grid[0].length;
        int total = m * n;
        parent = new int[total + 1];
        sz = new int[total + 1];
        for (int i = 0; i <= total; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        int[][] g = new int[m][n];
        for (int r = 0; r < m; r++) {
            g[r] = grid[r].clone();
        }
        for (int[] h : hits) {
            g[h[0]][h[1]] = 0;
        }

        for (int c = 0; c < n; c++) {
            if (g[0][c] == 1) unite(idx(0, c), total);
        }
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] == 1) {
                    if (g[r-1][c] == 1) unite(idx(r, c), idx(r-1, c));
                    if (c > 0 && g[r][c-1] == 1) unite(idx(r, c), idx(r, c-1));
                }
            }
        }

        int[] res = new int[hits.length];
        int prev = sz[find(total)];
        for (int i = hits.length - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                res[i] = 0;
                continue;
            }
            g[r][c] = 1;
            if (r == 0) unite(idx(r, c), total);
            if (r > 0 && g[r-1][c] == 1) unite(idx(r, c), idx(r-1, c));
            if (r < m-1 && g[r+1][c] == 1) unite(idx(r, c), idx(r+1, c));
            if (c > 0 && g[r][c-1] == 1) unite(idx(r, c), idx(r, c-1));
            if (c < n-1 && g[r][c+1] == 1) unite(idx(r, c), idx(r, c+1));

            int curr = sz[find(total)];
            res[i] = Math.max(0, curr - prev - 1);
            prev = curr;
        }
        return res;
    }
}