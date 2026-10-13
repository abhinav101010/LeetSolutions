import java.util.*;

class Solution {
    int[] parent;
    int[] sizeArr;
    int count;
    
    private int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    private void union(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (sizeArr[rx] < sizeArr[ry]) {
            int tmp = rx; rx = ry; ry = tmp;
        }
        parent[ry] = rx;
        sizeArr[rx] += sizeArr[ry];
        count--;
    }
    
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        parent = new int[m * n];
        for (int i = 0; i < parent.length; i++) parent[i] = i;
        sizeArr = new int[m * n];
        Arrays.fill(sizeArr, 1);
        count = 0;
        boolean[] grid = new boolean[m * n];
        List<Integer> res = new ArrayList<>();
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int[] p : positions) {
            int r = p[0], c = p[1];
            int idx = r * n + c;
            if (!grid[idx]) {
                grid[idx] = true;
                count++;
                for (int[] d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr * n + nc]) {
                        union(idx, nr * n + nc);
                    }
                }
            }
            res.add(count);
        }
        return res;
    }
}