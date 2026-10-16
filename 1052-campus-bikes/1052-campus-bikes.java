import java.util.*;
class Solution {
    static class Pair implements Comparable<Pair> {
        int d,i,j;
        Pair(int d,int i,int j){this.d=d;this.i=i;this.j=j;}
        public int compareTo(Pair o){ return Integer.compare(d,o.d); }
    }
    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length, m = bikes.length;
        List<Pair> pairs = new ArrayList<>();
        for (int i=0;i<n;i++) {
            int x1=workers[i][0], y1=workers[i][1];
            for (int j=0;j<m;j++) {
                int x2=bikes[j][0], y2=bikes[j][1];
                int d = Math.abs(x1-x2)+Math.abs(y1-y2);
                pairs.add(new Pair(d,i,j));
            }
        }
        Collections.sort(pairs);
        int[] res = new int[n];
        Arrays.fill(res, -1);
        boolean[] used = new boolean[m];
        for (Pair p:pairs) {
            if (res[p.i] == -1 && !used[p.j]) {
                res[p.i] = p.j;
                used[p.j] = true;
            }
            int cnt=0; for (boolean b:used) if (b) cnt++;
            if (cnt == n) break;
        }
        return res;
    }
}
