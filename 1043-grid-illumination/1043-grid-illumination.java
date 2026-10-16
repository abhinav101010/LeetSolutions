import java.util.*;
class Solution {
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        Map<Integer,Integer> rows=new HashMap<>(), cols=new HashMap<>();
        Map<Integer,Integer> d1=new HashMap<>(), d2=new HashMap<>();
        Set<Long> lampsSet=new HashSet<>();
        for (int[] l: lamps) {
            long key = ((long)l[0]<<32)| (l[1]&0xffffffffL);
            if (!lampsSet.contains(key)) {
                lampsSet.add(key);
                rows.put(l[0], rows.getOrDefault(l[0],0)+1);
                cols.put(l[1], cols.getOrDefault(l[1],0)+1);
                d1.put(l[0]-l[1], d1.getOrDefault(l[0]-l[1],0)+1);
                d2.put(l[0]+l[1], d2.getOrDefault(l[0]+l[1],0)+1);
            }
        }
        int[] res=new int[queries.length];
        for (int qi=0;qi<queries.length;qi++) {
            int x=queries[qi][0], y=queries[qi][1];
            if (rows.getOrDefault(x,0)>0 || cols.getOrDefault(y,0)>0 ||
                d1.getOrDefault(x-y,0)>0 || d2.getOrDefault(x+y,0)>0) {
                res[qi]=1;
            } else {
                res[qi]=0;
            }
            // turn off
            for (int nx=Math.max(0,x-1); nx<Math.min(N,x+2); nx++) {
                for (int ny=Math.max(0,y-1); ny<Math.min(N,y+2); ny++) {
                    long k2=((long)nx<<32)|(ny&0xffffffffL);
                    if (lampsSet.contains(k2)) {
                        lampsSet.remove(k2);
                        rows.put(nx, rows.getOrDefault(nx,1)-1);
                        cols.put(ny, cols.getOrDefault(ny,1)-1);
                        d1.put(nx-ny, d1.getOrDefault(nx-ny,1)-1);
                        d2.put(nx+ny, d2.getOrDefault(nx+ny,1)-1);
                    }
                }
            }
        }
        return res;
    }
}
