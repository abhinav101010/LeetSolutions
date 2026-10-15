import java.util.*;
class Solution {
    public int tallestBillboard(int[] rods) {
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(0, 0);
        for (int r : rods) {
            Map<Integer, Integer> newdp = new HashMap<>(dp);
            for (Map.Entry<Integer, Integer> entry : dp.entrySet()) {
                int diff = entry.getKey();
                int h = entry.getValue();
                // add to positive side
                int ndiff = diff + r;
                int nh = h + r;
                if (nh > newdp.getOrDefault(ndiff, 0)) {
                    newdp.put(ndiff, nh);
                }
                // add to negative side
                ndiff = diff - r;
                nh = h;
                if (nh > newdp.getOrDefault(ndiff, 0)) {
                    newdp.put(ndiff, nh);
                }
            }
            dp = newdp;
        }
        return dp.getOrDefault(0, 0);
    }
}
