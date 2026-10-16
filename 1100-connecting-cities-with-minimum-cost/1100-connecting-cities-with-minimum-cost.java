import java.util.*;
class Solution {
    int[] parent;
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    boolean union(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        parent[rx] = ry; return true;
    }
    public int minimumCost(int N, int[][] connections) {
        Arrays.sort(connections, (a, b) -> Integer.compare(a[2], b[2]));
        parent = new int[N + 1];
        for (int i = 0; i <= N; i++) parent[i] = i;
        int cost = 0, edges = 0;
        for (int[] c : connections) {
            if (union(c[0], c[1])) { cost += c[2]; edges++; }
        }
        return edges == N - 1 ? cost : -1;
    }
}
