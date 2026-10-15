import java.util.*;
class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet<>();
        for (int i = 0; i < fronts.length; i++) {
            if (fronts[i] == backs[i]) {
                same.add(fronts[i]);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int f : fronts) {
            if (!same.contains(f)) {
                ans = Math.min(ans, f);
            }
        }
        for (int b : backs) {
            if (!same.contains(b)) {
                ans = Math.min(ans, b);
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}
