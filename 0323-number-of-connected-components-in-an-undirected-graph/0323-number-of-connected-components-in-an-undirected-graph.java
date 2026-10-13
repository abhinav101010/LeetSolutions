import java.util.*;

class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        int[] sizeArr = new int[n];
        Arrays.fill(sizeArr, 1);
        int count = n;
        for (int[] e : edges) {
            int rx = find(parent, e[0]);
            int ry = find(parent, e[1]);
            if (rx != ry) {
                if (sizeArr[rx] < sizeArr[ry]) {
                    int tmp = rx; rx = ry; ry = tmp;
                }
                parent[ry] = rx;
                sizeArr[rx] += sizeArr[ry];
                count--;
            }
        }
        return count;
    }
    private int find(int[] parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
}