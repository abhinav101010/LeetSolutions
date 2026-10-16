import java.util.*;
class Solution {
    int[] parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    public int earliestAcq(int[][] logs, int N) {
        Arrays.sort(logs, (a,b) -> Integer.compare(a[0], b[0]));
        parent = new int[N];
        for (int i = 0; i < N; i++) parent[i] = i;
        int comp = N;
        for (int[] l : logs) {
            int ra = find(l[1]), rb = find(l[2]);
            if (ra != rb) { parent[ra] = rb; comp--; if (comp == 1) return l[0]; }
        }
        return -1;
    }
}
