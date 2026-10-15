import java.util.*;
class Solution {
    public int rectangleArea(int[][] rectangles) {
        final int MOD = 1000000007;
        List<int[]> events = new ArrayList<>();
        Set<Long> ySet = new HashSet<>();
        for (int[] r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            events.add(new int[]{x1, 1, y1, y2});
            events.add(new int[]{x2, -1, y1, y2});
            ySet.add((long) y1);
            ySet.add((long) y2);
        }
        List<Long> ys = new ArrayList<>(ySet);
        Collections.sort(ys);
        Map<Long, Integer> yToIdx = new HashMap<>();
        for (int i = 0; i < ys.size(); i++) {
            yToIdx.put(ys.get(i), i);
        }
        int[] cnt = new int[ys.size() - 1];
        Collections.sort(events, (a, b) -> Integer.compare(a[0], b[0]));
        long ans = 0;
        long prevX = events.get(0)[0];
        for (int[] e : events) {
            long x = e[0];
            long dx = x - prevX;
            if (dx != 0) {
                long covered = 0;
                for (int i = 0; i < cnt.length; i++) {
                    if (cnt[i] > 0) {
                        covered += (ys.get(i+1) - ys.get(i));
                    }
                }
                ans = (ans + dx * covered) % MOD;
            }
            prevX = x;
            int typ = e[1];
            long y1 = e[2];
            long y2 = e[3];
            int iIdx = yToIdx.get(y1);
            int jIdx = yToIdx.get(y2);
            for (int k = iIdx; k < jIdx; k++) {
                cnt[k] += typ;
            }
        }
        return (int) ans;
    }
}
